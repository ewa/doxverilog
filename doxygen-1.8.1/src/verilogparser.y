/******************************************************************************
* Copyright (c) M.Kreis,2009 
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU Library General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA
*
* You may use and distribute this software under the terms of the
* GNU General Public License, version 2 or later
*****************************************************************************/

/******************************************************************************
 * Simple Parser for Verilog 2001 subset
 * Date: 04/2008
 * supports the IEEE Std 1364-2001 (Revision of IEEE Std 1364-1995)Verilog subset
 * 
 *****************************************************************************/

%locations
%skeleton "glr.c" 
%name-prefix="c_"
%debug

%{

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include "verilogdocgen.h"
#include "membergroup.h"
//#include "verilogparser.hpp"
#include "vhdldocgen.h"
#include "doxygen.h"
#include "searchindex.h"
#include "verilogscanner.h"
#include "commentscan.h"
#include "arguments.h"
#define YYMAXDEPTH 15000

static MyParserConv* myconv=0;

static int CurrState;
static bool generateItem=false;
static int          currVerilogType;
static Entry*       current=0;
static Entry*		current_rootVerilog  ;
static Entry*		currentVerilog=0  ;
static Entry*       currentFunctionVerilog=0;
static Entry*       lastModule=0;



static Entry        prevDocEntryVerilog;

static bool         parseCode=FALSE; 

static QCString     currVerilogClass;
static QCString     identVerilog; // last written word
static QCString     currVerilogInst;
static QCString     prevName; // stores the last parsed word
static QCString     moduleParamName; // stores name of  module xxx#(paramList) xxx ();
static int          moduleLine=0;

static int briefLine;
static QCString briefString;

int c_lex (void);
void c_error (char const *);


// functions for  verilog parser ---------------------

static void parseString();
static void writeDigit();
static void initVerilogParser();
static void parseModule();
static void parseFunction(Entry* e);
static void parseReg(Entry* e);
static void parsePortDir(Entry* e,int type);
static void parseParam(Entry* e);
static void parseListOfPorts();
static void parseAlways(bool b=false);
static void parseModuleInst(QCString& first,QCString& sec);


bool findExtendsComponent(QList<BaseInfo> *extend,QCString& compName);
void addSubEntry(Entry* root, Entry* e);
%}

%union {
	int itype;	/* for count */
	char ctype;	/* for char */
	char cstr[VBUF_SIZE];
	}

%token NET_TOK STR0_TOK STR1_TOK GATE_TOK  STRING_TOK 
%token DIGIT_TOK UNDERSCORE_TOK SEM_TOK DOT_TOK 
%token LETTER_TOK  PLUS_TOK MINUS_TOK
%token COLON_TOK LBRACE_TOK RBRACE_TOK LBRACKET_TOK RBRACKET_TOK AND_TOK
%token OR_TOK EQU_TOK GT_TOK LT_TOK NOT_TOK  MULT_TOK PERCENTAL_TOK
%token ENV_TOK PARA_TOK CHAR_TOK AT_TOK DOLLAR_TOK BASE_TOK
%token SN_TOK EXCLAMATION_TOK RRAM_TOK LRAM_TOK
%token PARAMETER_TOK  OUTPUT_TOK INOUT_TOK
%token SMALL_TOK MEDIUM_TOK LARGE_TOK VEC_TOK SCALAR_TOK REG_TOK TIME_TOK REAL_TOK  EVENT_TOK
%token ASSIGN_TOK DEFPARAM_TOK MODUL_TOK ENDMODUL_TOK MACRO_MODUL_TOK
%token ENDPRIMITIVE_TOK PRIMITIVE_TOK INITIAL_TOK TABLE_TOK ENDTABLE_TOK ALWAYS_TOK
%token TASK_TOK ENDTASK_TOK FUNC_TOK ENDFUNC_TOK
%token IF_TOK CASE_TOK CASEX_TOK CASEZ_TOK FOREVER_TOK REPEAT_TOK
%token FOR_TOK JOIN_TOK WAIT_TOK FORCE_TOK RELEASE_TOK DEASSIGN_TOK DISABLE_TOK
%token  WHILE_TOK ELSE_TOK ENDCASE_TOK BEGIN_TOK DEFAULT_TOK FORK_TOK
%token END_TOK SPECIFY_TOK ENDSPECIFY_TOK SPECPARAM_TOK
%token DSETUP_TOK DHOLD_TOK  DWIDTH_TOK DPERIOD_TOK DSKEW_TOK DRECOVERY_TOK DSETUPHOLD_TOK
%token POSEDGE_TOK NEGEDGE_TOK EDGE_TOK
%token COMMA_TOK  QUESTION_TOK AUTO_TOK
%token  INPUT_TOK SIGNED_TOK LOCALPARAM_TOK 
%token  INTEGER_TOK  NOCHANGE_TOK
%token  GENERATE_TOK ENDGENERATE_TOK  GENVAR_TOK
%token  LIBRARY_TOK CONFIG_TOK ENDCONFIG_TOK INCLUDE_TOK PULSEON_DETECT_TOK PULSEONE_EVENT_TOK
%token  USE_TOK LIBLIST_TOK INSTANCE_TOK CELL_TOK SHOWCANCEL_TOK NOSHOWCANCEL_TOK
%token  REMOVAL_TOK FULLSKEW_TOK TIMESKEW_TOK RECREM_TOK
%token IFNONE_TOK REALTIME_TOK DESIGN_TOK 
%token ATL_TOK ATR_TOK OOR_TOK AAND_TOK SNNOT_TOK NOTSN_TOK AAAND_TOK
%token DEFINE_TOK 

%initial-action { yydebug=0; } 
%start file 
/* -------------- rules section -------------- */
%%
file	: lines 	
	    ;
lines 	: {identVerilog.resize(0);} description  
           | lines  description {identVerilog.resize(0);}
	//	   | module_or_generate_item // for parsing inline source code (functions/always/tasks)  caused problem with (* bla bla *)module
		   ;


//------------------------------------------------------------------------------------------------------
//----------------------------   A.1.1 Library source text  -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

library_text : library_descriptions
              ; 
library_descriptions :  include_statement   {vbufreset();}
			         | library_declaration {vbufreset();}
                     | config_declaration  {vbufreset();}
					 ;

library_declaration : LIBRARY_TOK SEM_TOK  //  | parse in verlogscanner.l 
					;

identifier_lib : identifier {
                                if(!parseCode) 
								{ 
								   QCString libName=$<cstr>1;
								   Entry *lib=VerilogDocGen::makeNewEntry(libName.data(),Entry::VARIABLE_SEC,VerilogDocGen::LIBRARY,c_lloc.first_line);
                                   lib->type="library";
								   addGlobalVerilogMember(lib);
								}          
				            }

file_path_spec : simple_identifier
                | STRING_TOK
				;

include_statement :  INCLUDE_TOK GT_TOK file_path_spec LT_TOK SEM_TOK
                   | INCLUDE_TOK error SEM_TOK
				   ;
//------------------------------------------------------------------------------------------------------
//----------------------------  A.1.2 Configuration source text  -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

config_declaration : CONFIG_TOK identifier_conf SEM_TOK  design_statement config_rule_statement_list ENDCONFIG_TOK
                   | CONFIG_TOK identifier_conf SEM_TOK  design_statement  ENDCONFIG_TOK      
				   | CONFIG_TOK identifier_conf SEM_TOK error  ENDCONFIG_TOK      				   
				  ; 

identifier_conf : identifier {
                                if(!parseCode) 
								{ 
								   QCString confName=$<cstr>1;
								   Entry *conf=VerilogDocGen::makeNewEntry(confName.data(),Entry::VARIABLE_SEC,VerilogDocGen::CONFIGURATION,c_lloc.first_line);
                                   conf->type="configuration";
								   addGlobalVerilogMember(conf);
								}          
				            }

design_statement : DESIGN_TOK  aidentifier_list  SEM_TOK
                 | DESIGN_TOK error SEM_TOK
				 ;



config_rule_statement_list:config_rule_statement
                          | config_rule_statement_list config_rule_statement
						  ;


config_rule_statement : DEFAULT_TOK liblist_clause SEM_TOK
                      | inst_clause liblist_clause SEM_TOK
                      | inst_clause use_clause SEM_TOK
                      | cell_clause liblist_clause SEM_TOK
                      | cell_clause use_clause SEM_TOK
					  ;


aidentifier_list : simple_identifier
                | aidentifier_list simple_identifier
                ;


inst_clause :INSTANCE_TOK simple_identifier
            ;

cell_clause : CELL_TOK simple_identifier
            ;
             

liblist_clause : LIBLIST_TOK  
               | LIBLIST_TOK aidentifier_list 
               ;

use_clause : USE_TOK simple_identifier config 
		    ;  

config : /* empty */
       | COLON_TOK CONFIG_TOK


//------------------------------------------------------------------------------------------------------
//---------------------------- -- A.1.3 Module and primitive source text  -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

description : module_declaration {}
	         | udp_declaration
           //  | DEFINE_TOK identifier  expression
           //  | INCLUDE_TOK  expression
             | library_text
			 ;


module_declaration : attribute_instance module_keyword    SEM_TOK module_option  end_mod
					| attribute_instance module_keyword   SEM_TOK  end_mod
					|  attribute_instance  module_keyword    module_parameter_port_list 
                       SEM_TOK  module_option  end_mod				
					|  attribute_instance module_keyword   list_of_ports  SEM_TOK  module_option  end_mod
                    |  attribute_instance module_keyword   list_of_port_declarations  SEM_TOK  module_option  end_mod
                    |  attribute_instance module_keyword   list_of_port_declarations  SEM_TOK  error end_mod
                 	|  attribute_instance module_keyword   list_of_ports  SEM_TOK  error  end_mod    
				  	|  attribute_instance module_keyword LBRACE_TOK RBRACE_TOK SEM_TOK module_option  end_mod
		      		|  attribute_instance module_keyword module_parameter_port_list   list_of_ports  SEM_TOK  module_option  end_mod
                    |  attribute_instance module_keyword  module_parameter_port_list list_of_port_declarations  SEM_TOK  module_option  end_mod
					;

					

name_of_module  : identifier 
                ;

module_type: MODUL_TOK
            | MACRO_MODUL_TOK  

module_keyword : module_type name_of_module {
                                    yydebug=0; //sets parser in debug mode
                                    if(!parseCode) { 
							              
											 lastModule=VerilogDocGen::makeNewEntry("",Entry::CLASS_SEC,VerilogDocGen::MODULE);
                                            currentVerilog=lastModule;
                                             currentVerilog->protection=Public;
					                         parseModule();
							                 CurrState=VerilogDocGen::STATE_MODULE;
				                             
										    }
                                            else {
											      parseModule();
                                         		  }
                               currVerilogType=0;						       
							   vbufreset();
							 }
			   ;

end_mod :  {
            if(!parseCode){ 
			        int ll=getVerilogLine();
	                currentVerilog->endBodyLine=ll;
			       } 	 
              vbufreset(); 
		   } ENDMODUL_TOK {currentVerilog=0;vbufreset();}

module_option : module_item
             | module_option module_item
		     ;

//------------------------------------------------------------------------------------------------------
//---------------------------- A.1.4 Module parameters and ports  -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

module_parameter_port_list : PARA_TOK LBRACE_TOK {currVerilogType=VerilogDocGen::PORT;} parameter_declaration_list  RBRACE_TOK               {currVerilogType=0;vbufreset();}
				| PARA_TOK  LBRACE_TOK error RBRACE_TOK {vbufreset();}
						   ;

parameter_declaration_list:  PARAMETER_TOK  { currVerilogType=VerilogDocGen::PARAMETER;} signed_range param_assignment                                      {currVerilogType=0;}
                          | parameter_declaration_list COMMA_TOK PARAMETER_TOK  { currVerilogType=VerilogDocGen::PARAMETER;}signed_range  param_assignment {currVerilogType=0;}
						  ;

signed_range: //empty
   | range
   | signed
   | signed range
   ;

list_of_ports :  LBRACE_TOK                    {currVerilogType=VerilogDocGen::PORT;} port_list RBRACE_TOK                                     {currVerilogType=0;vbufreset();}
               | LBRACE_TOK error RBRACE_TOK {currVerilogType=0;vbufreset();}
			  ;


list_of_port_declarations :  LBRACE_TOK task_port_list RBRACE_TOK {currVerilogType=0;vbufreset();}
                             ;


 port_list : port                       {parseListOfPorts();vbufreset();}
           | port_list COMMA_TOK port {parseListOfPorts();vbufreset();}
		   ;

port : port_expression 
     | DOT_TOK port_expression LBRACE_TOK RBRACE_TOK
	 | DOT_TOK port_expression LBRACE_TOK port_expression RBRACE_TOK 


port_expression : port_reference
                |  LRAM_TOK  port_reference_list RRAM_TOK
				;

port_reference_list: port_reference_list COMMA_TOK port_reference
                   | port_reference
                   ;

port_reference : identifier
               | DIGIT_TOK
			   | identifier LBRACKET_TOK expression RBRACKET_TOK
			   | identifier LBRACKET_TOK range_expression RBRACKET_TOK
			    ;

port_declaration : attribute_instance inout_declaration  { currVerilogType=0;vbufreset();}
                 | attribute_instance input_declaration  { currVerilogType=0;vbufreset();}
                 | attribute_instance output_declaration { currVerilogType=0;vbufreset();}
                 | error SEM_TOK	{ vbufreset();}			
				;

//------------------------------------------------------------------------------------------------------
//---------------------------- A.1.5 Module items  -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------

module_item : module_or_generate_item
            | port_declaration SEM_TOK
			|  port_declaration error SEM_TOK                {vbufreset();}
            |  attribute_instance  generated_instantiation     {vbufreset();}
            |  attribute_instance  local_parameter_declaration
            |  attribute_instance  parameter_declaration
            |  attribute_instance  specify_block               {vbufreset();}
            |  attribute_instance  specparam_declaration



module_or_generate_item : attribute_instance module_or_generate_item_declaration       {vbufreset();}
                        |  attribute_instance  parameter_override    {vbufreset();}
                        |  attribute_instance  continuous_assign     {vbufreset();}
                        |  attribute_instance  gate_instantiation    {vbufreset();}
                        |  attribute_instance  udp_instantiation     {vbufreset();}
                        |  attribute_instance  module_instantiation   {vbufreset();}
                        |  attribute_instance  initial_construct      {vbufreset();}
                        |  attribute_instance  always_construct       
						;

module_or_generate_item_declaration : net_declaration 
                                    | reg_declaration
                                    | integer_declaration
                                    | real_declaration
                                    | time_declaration
                                    | realtime_declaration
                                    | event_declaration
                                    | genvar_declaration  {vbufreset();}
                                    | task_declaration    {}
                                    | function_declaration{}
                                    ;


parameter_override : DEFPARAM_TOK { if(parseCode) currVerilogType=VerilogDocGen::DEFPARAM;} list_of_param_assignments SEM_TOK   {vbufreset(); if(parseCode) currVerilogType=0; }
                   | DEFPARAM_TOK error SEM_TOK                                                                                 {vbufreset(); if(parseCode) currVerilogType=0;} 
                   ;


//------------------------------------------------------------------------------------------------------
//---------------------------- A.2.1 Declaration types
//-----------------------------------------------------------------------------------------------------

local_parameter_declaration : LOCALPARAM_TOK   range { currVerilogType=VerilogDocGen::PARAMETER;} list_of_param_assignments SEM_TOK             {currVerilogType=0;vbufreset();}
                             | LOCALPARAM_TOK task_port_type { currVerilogType=VerilogDocGen::PARAMETER;} list_of_param_assignments SEM_TOK     {currVerilogType=0;vbufreset();}
                             | LOCALPARAM_TOK   { currVerilogType=VerilogDocGen::PARAMETER;} list_of_param_assignments SEM_TOK                  {currVerilogType=0;vbufreset();}
							 | LOCALPARAM_TOK signed  { currVerilogType=VerilogDocGen::PARAMETER;} list_of_param_assignments SEM_TOK            {currVerilogType=0;vbufreset();}
							 | LOCALPARAM_TOK  signed range { currVerilogType=VerilogDocGen::PARAMETER;} list_of_param_assignments SEM_TOK      {currVerilogType=0;vbufreset();}
							 | LOCALPARAM_TOK error SEM_TOK 
							 ;

parameter_declaration :        PARAMETER_TOK  { currVerilogType=VerilogDocGen::PARAMETER;}   list_of_param_assignments SEM_TOK                   {currVerilogType=0;vbufreset();}
                             | PARAMETER_TOK  task_port_type { currVerilogType=VerilogDocGen::PARAMETER;}   list_of_param_assignments SEM_TOK   {currVerilogType=0;vbufreset();}
                             | PARAMETER_TOK  signed  range  { currVerilogType=VerilogDocGen::PARAMETER;} list_of_param_assignments SEM_TOK    {currVerilogType=0;vbufreset();}
					         | PARAMETER_TOK    range  { currVerilogType=VerilogDocGen::PARAMETER;} list_of_param_assignments SEM_TOK	        {currVerilogType=0;vbufreset();}			
 					         | PARAMETER_TOK    signed  { currVerilogType=VerilogDocGen::PARAMETER;} list_of_param_assignments SEM_TOK	        {currVerilogType=0;vbufreset();}			
							 | PARAMETER_TOK error SEM_TOK {currVerilogType=0;vbufreset();}
							 ;

specparam_declaration : SPECPARAM_TOK  range  list_of_specparam_assignments SEM_TOK  { vbufreset();}
				      | SPECPARAM_TOK   list_of_specparam_assignments SEM_TOK        { vbufreset();}
                      | SPECPARAM_TOK error SEM_TOK 
					  ;

//------------------------------------------------------------------------------------------------------
//---------------------------- A.2.1.2 Port declarations ---------------------------------------------
//-----------------------------------------------------------------------------------------------------

inout_declaration :  INOUT_TOK   xsigned xrange          { currVerilogType=VerilogDocGen::INOUT; } identifier    {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
				   | INOUT_TOK   net_type xsigned xrange { currVerilogType=VerilogDocGen::INOUT; } identifier    {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
				   | inout_declaration COMMA_TOK xsigned xrange identifier                                       {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
				   | inout_declaration COMMA_TOK net_type xsigned xrange identifier                              {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}			  
				   ;

input_declaration :  INPUT_TOK xsigned xrange          { currVerilogType=VerilogDocGen::INPUT; }  identifier      {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
				   | INPUT_TOK net_type xsigned xrange { currVerilogType=VerilogDocGen::INPUT; }  identifier      {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
				   | input_declaration COMMA_TOK xsigned xrange identifier                                        {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
				   | input_declaration COMMA_TOK net_type xsigned xrange identifier                               {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
			      // | INPUT_TOK error SEM_TOK {vbufreset();}
				   ;


output_declaration : OUTPUT_TOK  s_type { currVerilogType=VerilogDocGen::OUTPUT; }identifier                     {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
				   | OUTPUT_TOK   { currVerilogType=VerilogDocGen::OUTPUT; }  identifier                         {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
				//   | OUTPUT_TOK output_declaration net_assignment
                   | OUTPUT_TOK   { currVerilogType=VerilogDocGen::OUTPUT; }                           {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
								
				   | output_declaration COMMA_TOK  OUTPUT_TOK net_assignment
            	   | output_declaration COMMA_TOK identifier                                                     {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
			       | output_declaration COMMA_TOK OUTPUT_TOK s_type identifier                                 {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}		
			       | output_declaration COMMA_TOK OUTPUT_TOK  identifier                                       {if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}					   
			       ;

//------------------------------------------------------------------------------------------------------
//---------------------------- A.2.2.1 Net and variable types ---------------------------------------------
//-----------------------------------------------------------------------------------------------------


output_var_type:TIME_TOK
               | INTEGER_TOK
			   ;


s_type : net_type
           | range
		   | signed
		   | REG_TOK
		   | s_type SIGNED_TOK
		   | s_type range
      	   | s_type output_var_type
		   ;



net_type : NET_TOK
		 ;


event_declaration : EVENT_TOK list_of_event_identifiers SEM_TOK{ vbufreset();}
                   | EVENT_TOK error SEM_TOK { vbufreset();} 
				   ;

genvar_declaration :GENVAR_TOK list_of_genvar_identifiers SEM_TOK
                   | GENVAR_TOK error SEM_TOK 
				    ;

integer_declaration :INTEGER_TOK  list_of_variable_identifiers SEM_TOK {vbufreset();}
                    | INTEGER_TOK error SEM_TOK 
					;


net_declaration : NET_TOK     xscalared xsigned xrange list_of_net_identifiers  SEM_TOK                                {vbufreset();} 
                | NET_TOK xscalared xsigned xrange     list_of_net_decl_assignments  SEM_TOK                        {vbufreset();} 
	            | NET_TOK xscalared xsigned xrange  delay3   list_of_net_decl_assignments SEM_TOK                  {vbufreset();} 
	            | NET_TOK xscalared xsigned xrange  delay3   list_of_net_identifiers SEM_TOK                  {vbufreset();}   
	            | NET_TOK drive_strength xscalared xsigned xrange  delay3   list_of_net_decl_assignments SEM_TOK   {vbufreset();} 
	            | NET_TOK drive_strength xscalared xsigned xrange    list_of_net_decl_assignments SEM_TOK          {vbufreset();} 
	            | NET_TOK drive_strength xscalared xsigned xrange    list_of_net_identifiers SEM_TOK          {vbufreset();}      
	            | NET_TOK  charge_strength xscalared xsigned xrange     list_of_net_identifiers SEM_TOK        {vbufreset();} 
	            | NET_TOK charge_strength xscalared xsigned xrange delay3    list_of_net_identifiers SEM_TOK        {vbufreset();} 			  
	            | NET_TOK charge_strength xscalared xsigned xrange     list_of_net_decl_assignments SEM_TOK  {vbufreset();}   
	            | NET_TOK  error SEM_TOK                                                                     {vbufreset();} 
			   	;


xscalared:/*empty*/ 
		| scalared
		;


scalared: VEC_TOK 
		| SCALAR_TOK
		;

real_declaration : REAL_TOK  list_of_variable_identifiers SEM_TOK  {vbufreset();currVerilogType=0;} 
                 | REAL_TOK error SEM_TOK                      {vbufreset();} 
				 ;
realtime_declaration : REALTIME_TOK { currVerilogType=VerilogDocGen::TIME; }list_of_variable_identifiers SEM_TOK {vbufreset();currVerilogType=0;} 
                     | REALTIME_TOK error SEM_TOK {vbufreset();}
					 ; 

reg_declaration : REG_TOK  xsigned  range list_of_variable_identifiers SEM_TOK {currVerilogType=0;}
                | REG_TOK   xsigned  list_of_variable_identifiers SEM_TOK {currVerilogType=0;}
                | REG_TOK error SEM_TOK { vbufreset();}
				 ;

time_declaration : TIME_TOK { currVerilogType=VerilogDocGen::TIME; } list_of_variable_identifiers SEM_TOK  {vbufreset();currVerilogType=0;} 
                 | TIME_TOK error SEM_TOK                          {vbufreset();} 
				 ;

dimension_list: dimension
              | dimension_list dimension
			   ;

//------------------------------------------------------------------------------------------------------
//---------------------------- A.2.2.2 Strengths --------------------------------------------
//-----------------------------------------------------------------------------------------------------

drive_strength:  LBRACE_TOK STR0_TOK COMMA_TOK STR1_TOK RBRACE_TOK
	            | LBRACE_TOK STR1_TOK COMMA_TOK STR0_TOK RBRACE_TOK
                | LBRACE_TOK error RBRACE_TOK
			//	| drive_strength SIGNED_TOK
				;


charge_strength : LBRACE_TOK SMALL_TOK RBRACE_TOK
             	| LBRACE_TOK MEDIUM_TOK RBRACE_TOK
	            | LBRACE_TOK LARGE_TOK RBRACE_TOK
           		;


//------------------------------------------------------------------------------------------------------
//----------------------------A.2.2.3 Delays --------------------------------------------
//-----------------------------------------------------------------------------------------------------


delay3 :  PARA_TOK LBRACE_TOK delay_value_list RBRACE_TOK {}
        | PARA_TOK delay_value 
	   ;

delay_value_list : delay_value 
                 | delay_value_list COMMA_TOK delay_value
				 ;

delay2 : delay3
       ;
	   
delay_value : mintypemax_expression
            ;

//------------------------------------------------------------------------------------------------------
//----------------------------A.2.3 Declaration lists --------------------------------------------
//-----------------------------------------------------------------------------------------------------

list_of_event_identifiers : list_of_event_lists  
						    | dim_list {if(!parseCode) {parseReg(currentVerilog);}vbufreset();} 
							;

list_of_event_lists:identifier       {if(!parseCode) {parseReg(currentVerilog);}vbufreset();} 
                   |list_of_event_lists COMMA_TOK identifier  {if(!parseCode) {parseReg(currentVerilog);}vbufreset();} 
                   ;


dim_list: identifier dimension_list
          | dim_list COMMA_TOK identifier dimension_list
		   ;
		    

list_of_genvar_identifiers : identifier 
                           | list_of_genvar_identifiers COMMA_TOK identifier
						    ;
							
list_of_net_decl_assignments : net_decl_assignment  
                              | list_of_net_decl_assignments COMMA_TOK net_decl_assignment  
 							  ;

list_of_net_identifiers : list_of_event_identifiers 
                        ;

list_of_param_assignments : param_assignment 
                          | list_of_param_assignments COMMA_TOK param_assignment 
						  ;

						 

real_type : identifier 
          | identifier EQU_TOK expression 
          | identifier dimension_list
		  ;

variable_type:real_type
              ;


list_of_specparam_assignments : specparam_assignment 
							   | list_of_specparam_assignments COMMA_TOK specparam_assignment 				
                               ;

list_of_variable_identifiers  : variable_type                                          {if(!parseCode) {
                                                                   							parseReg(currentVerilog);}
																							vbufreset();} 
						      |	list_of_variable_identifiers COMMA_TOK variable_type {if(!parseCode) parseReg(currentVerilog);vbufreset();} 
							  ;
							  
  
//------------------------------------------------------------------------------------------------------
//----------------------------A.2.4 Declaration assignments --------------------------------------------
//-----------------------------------------------------------------------------------------------------
      
net_decl_assignment :identifier EQU_TOK expression {if(!parseCode) {parseReg(currentVerilog);}vbufreset();} 
                    ; 
param_assignment :simple_identifier EQU_TOK expression {
                          			 if(currVerilogType==VerilogDocGen::PARAMETER && !parseCode)
									 parseParam(currentVerilog);
									 vbufreset();
	                   }
                 ;
				 
specparam_assignment : identifier EQU_TOK mintypemax_expression
                   //  | PATHPULSE_TOK EQU_TOK constant_mintypmax_expression 
					  ;

//------------------------------------------------------------------------------------------------------
//----------------------------A.2.5 Declaration ranges --------------------------------------------
//-----------------------------------------------------------------------------------------------------

dimension : LBRACKET_TOK dimension_constant_expression COLON_TOK dimension_constant_expression RBRACKET_TOK
           ;

range :  LBRACKET_TOK msb_constant_expression COLON_TOK lsb_constant_expression RBRACKET_TOK
       ;


//------------------------------------------------------------------------------------------------------
//----------------------------A.2.6 Function declarations --------------------------------------------
//-----------------------------------------------------------------------------------------------------

function_declaration : FUNC_TOK  automatic xsigned  range_or_type  name_of_function SEM_TOK 
                        function_item_declaration_list 
                        function_statement
                        ENDFUNC_TOK                  {if(!parseCode && currentFunctionVerilog)
						                                {
														  currentFunctionVerilog->endBodyLine=getVerilogPrevLine();
														} vbufreset(); }

					  | FUNC_TOK  automatic xsigned range_or_type name_of_function LBRACE_TOK function_port_list RBRACE_TOK SEM_TOK 
                        block_item_declaration_list 
                        function_statement
                        ENDFUNC_TOK                  {if(!parseCode && currentFunctionVerilog){currentFunctionVerilog->endBodyLine=getVerilogPrevLine();} vbufreset(); }
                      | FUNC_TOK  automatic xsigned range_or_type name_of_function LBRACE_TOK function_port_list RBRACE_TOK SEM_TOK 
                        function_statement
                        ENDFUNC_TOK					
					  | FUNC_TOK error ENDFUNC_TOK { vbufreset(); }
					  ;
 

name_of_function : identifier {  if(!parseCode){
                             //    printf("\n  funcname [%s] --\n",getVerilogString());
                                 currentFunctionVerilog=VerilogDocGen::makeNewEntry("",Entry::FUNCTION_SEC,VerilogDocGen::FUNCTION);
								 currentFunctionVerilog->fileName=getVerilogParsingFile();
								 parseFunction(currentFunctionVerilog);
								 CurrState=VerilogDocGen::STATE_FUNCTION;
								 }
								 vbufreset();
							   }
        
				 ;


range_or_type : /*empty*/
              | range
	          | INTEGER_TOK 
	          | REAL_TOK
			  | TIME_TOK
              | REALTIME_TOK
			  ;


 automatic: /*empty*/
          | AUTO_TOK
		  ;

xsigned: /*empty*/
       | SIGNED_TOK
	   ;

 function_item_declaration_list :  function_item_declaration
							     | function_item_declaration_list   function_item_declaration
								 ;
								 
			
function_item_declaration : block_item_declaration
                          | tf_input_declaration_list SEM_TOK { currVerilogType=0;}
                  		   ;


function_port_list : attribute_instance tf_input_declaration// attribute_instance tf_input_declaration 
                   | function_port_list COMMA_TOK  tf_input_declaration
                    ;


//------------------------------------------------------------------------------------------------------
//---------------------------- A.2.7 Task declarations  --------------------------------------------
//-----------------------------------------------------------------------------------------------------

task_declaration : TASK_TOK   automatic  name_of_task SEM_TOK 
                    task_item_declaration_list statement_list ENDTASK_TOK                                      {if(!parseCode && currentFunctionVerilog) { currentFunctionVerilog->endBodyLine=getVerilogPrevLine();} vbufreset();}
                 | TASK_TOK   automatic  name_of_task SEM_TOK 
                    statement_list ENDTASK_TOK                 
                 |  TASK_TOK  automatic  name_of_task  LBRACE_TOK  task_port_list RBRACE_TOK SEM_TOK 
                    block_item_declaration_list statement_list ENDTASK_TOK                                     {if(!parseCode && currentFunctionVerilog) { currentFunctionVerilog->endBodyLine=getVerilogPrevLine();} vbufreset();}
                 |  TASK_TOK  automatic  name_of_task LBRACE_TOK  task_port_list RBRACE_TOK SEM_TOK 
                     statement_list ENDTASK_TOK                                                                {if(!parseCode && currentFunctionVerilog) { currentFunctionVerilog->endBodyLine=getVerilogPrevLine();} vbufreset();}
				 | TASK_TOK error ENDTASK_TOK                                                                { vbufreset();}
				 ;

name_of_task : identifier {  if(!parseCode){
                             //    printf("\n  funcname [%s] --\n",getVerilogString());
                                 currentFunctionVerilog=VerilogDocGen::makeNewEntry("",Entry::FUNCTION_SEC,VerilogDocGen::TASK);
								 currentFunctionVerilog->fileName=getVerilogParsingFile();
								 parseFunction(currentFunctionVerilog);
								 CurrState=VerilogDocGen::STATE_FUNCTION;
								 }
								 vbufreset();
							   }
        
				 ;				 
				 
block_item_declaration_list :block_item_declaration_list block_item_declaration
							|  block_item_declaration
							;

task_item_declaration_list :task_item_declaration_list task_item_declaration
							|  task_item_declaration
                             ;


task_item_declaration : block_item_declaration
                         | task_port_item SEM_TOK
						 ;


task_port_list :task_port_item 
               | task_port_list COMMA_TOK task_port_item 
			   ;
			   


task_port_item :  tf_port_declaration 
               ;


tf_port_declaration : tf_port_dir xsigned xreg  xrange  identifier {
                             if(!parseCode){
							   parsePortDir(currentVerilog,3);}
							   vbufreset();
                     }
                	 | tf_port_dir task_port_type  identifier  {if(!parseCode){
							   parsePortDir(currentVerilog,3);}
							   vbufreset();
                      }
                     | tf_port_declaration COMMA_TOK task_port_type  identifier  {if(!parseCode){
							   parsePortDir(currentVerilog,3);}
							   vbufreset();
                       }
				 
				 	 | tf_port_declaration COMMA_TOK xsigned xreg  xrange identifier {
                             if(!parseCode){
							   parsePortDir(currentVerilog,3);}
							   vbufreset();
                   }
					 | tf_port_declaration COMMA_TOK tf_port_dir xsigned xreg  xrange  identifier {
                             if(!parseCode){
							   parsePortDir(currentVerilog,3);}
							   vbufreset();
                    }
				//  |tf_port_dir error SEM_TOK
					 ; 

xreg:/*empty*/
    | REG_TOK

xrange:/*empty*/
      | range
	  ;
xnettype:/*empty*/
     | NET_TOK
     ;

tf_port_dir: attribute_instance INOUT_TOK   xnettype    { if(!parseCode )currVerilogType=VerilogDocGen::INOUT;}
           |  attribute_instance OUTPUT_TOK xnettype  { if(!parseCode)currVerilogType=VerilogDocGen::OUTPUT;}
		   |  attribute_instance INPUT_TOK  xnettype { if(!parseCode)currVerilogType=VerilogDocGen::INPUT;}
		   |  tf_port_dir COMMA_TOK identifier { if(!parseCode){parsePortDir(currentVerilog,3);vbufreset();}} 
		   ;


tf_input_declaration_list:tf_input_declaration
                         | tf_input_declaration_list COMMA_TOK tf_input_declaration
					 	 ;

tf_input_declaration : INPUT_TOK   xsigned   xrange  identifier                                         {if(!parseCode){currVerilogType=VerilogDocGen::INPUT;parsePortDir(currentVerilog,3);}vbufreset();}
                     | INPUT_TOK   REG_TOK  xsigned  xrange  identifier                               {if(!parseCode){currVerilogType=VerilogDocGen::INPUT;parsePortDir(currentVerilog,3);}vbufreset();}
                     | INPUT_TOK task_port_type  identifier                                             {if(!parseCode){currVerilogType=VerilogDocGen::INPUT;parsePortDir(currentVerilog,3);}vbufreset();}
                     | tf_input_declaration COMMA_TOK identifier                                        {if(!parseCode){currVerilogType=VerilogDocGen::INPUT;parsePortDir(currentVerilog,3);}vbufreset();}
				     | tf_input_declaration COMMA_TOK INPUT_TOK xsigned xrange identifier             {if(!parseCode){currVerilogType=VerilogDocGen::INPUT;parsePortDir(currentVerilog,3);}vbufreset();}
					 | tf_input_declaration COMMA_TOK INPUT_TOK REG_TOK xsigned xrange identifier   {if(!parseCode){currVerilogType=VerilogDocGen::INPUT;parsePortDir(currentVerilog,3);}vbufreset();}
				     | tf_input_declaration COMMA_TOK INPUT_TOK task_port_type identifier             {if(!parseCode){currVerilogType=VerilogDocGen::INPUT;parsePortDir(currentVerilog,3);}vbufreset();}
				    | INPUT_TOK error SEM_TOK { vbufreset(); }  
					 ; 


task_port_type : TIME_TOK      
               | REAL_TOK     
			   | REALTIME_TOK  
			   | INTEGER_TOK   
			   ;

//------------------------------------------------------------------------------------------------------
//---------------------------- A.2.8 Block item declarations   --------------------------------------------
//-----------------------------------------------------------------------------------------------------

block_item_declaration :  attribute_instance  block_reg_declaration
                       |  attribute_instance  event_declaration
                       |  attribute_instance  integer_declaration
                       |  attribute_instance  local_parameter_declaration 
                       |  attribute_instance  parameter_declaration
                       |  attribute_instance  real_declaration
                       |  attribute_instance  realtime_declaration
                       |  attribute_instance  time_declaration
                       ;

block_reg_declaration : REG_TOK    range list_of_block_variable_identifiers SEM_TOK  {vbufreset();}
                      | REG_TOK   signed range list_of_block_variable_identifiers SEM_TOK  {vbufreset();}
					  | REG_TOK    list_of_block_variable_identifiers SEM_TOK  {vbufreset();}
                      ;


list_of_block_variable_identifiers : block_variable_type 
                                   | list_of_block_variable_identifiers COMMA_TOK block_variable_type 
                                   ;

block_variable_type : identifier
                    | identifier dimension_list
					;

//------------------------------------------------------------------------------------------------------
//---------------------------- A.3.1 Primitive instantiation and instances    --------------------------------------------
//-----------------------------------------------------------------------------------------------------

gate_instantiation : GATE_TOK delay3 cmos_switch_instance_list SEM_TOK 
				   | GATE_TOK cmos_switch_instance_list SEM_TOK
				   | GATE_TOK drive_strength cmos_switch_instance_list SEM_TOK				  
				   | GATE_TOK drive_strength delay3 cmos_switch_instance_list SEM_TOK				  
			       | GATE_TOK pull_gate_instance_list SEM_TOK           
				   | GATE_TOK error SEM_TOK { vbufreset(); }
				   ;

pull_gate_instance_list: pull_gate_instance
                       | pull_gate_instance_list COMMA_TOK pull_gate_instance
					   ;

cmos_switch_instance_list:cmos_switch_instance
                         | cmos_switch_instance_list COMMA_TOK cmos_switch_instance
                          ;



cmos_switch_instance :name_of_gate_instance  LBRACE_TOK output_terminal COMMA_TOK expression_list RBRACE_TOK
                     | LBRACE_TOK output_terminal COMMA_TOK expression_list RBRACE_TOK
                     ; 



pull_gate_instance : name_of_gate_instance  LBRACE_TOK output_terminal RBRACE_TOK
                   | LBRACE_TOK output_terminal RBRACE_TOK
				   ;  

name_of_gate_instance : identifier range 
                      | identifier
					  ;

//------------------------------------------------------------------------------------------------------
//---------------------------- A.3.2 Primitive strengths  --------------------------------------------
//-----------------------------------------------------------------------------------------------------


output_terminal : net_lvalue
                ;

//------------------------------------------------------------------------------------------------------
//---------------------------- A.4.1 Module instantiation  --------------------------------------------
//-----------------------------------------------------------------------------------------------------

module_instantiation : module_identifier
					 ;

module_identifier          :  identifier { 
                    						     moduleParamName=prevName;	
                    					         moduleLine=c_lloc.first_line;
                    						} parameter_value_assignment module_instance_list {vbufreset();moduleLine=0;}SEM_TOK 
					 | identifier  module_instance_list {vbufreset();} SEM_TOK 
					 ;


module_instance_list: module_instance 
                      | module_instance_list COMMA_TOK module_instance 
                     ;

parameter_value_assignment : PARA_TOK LBRACE_TOK list_of_parameter_assignments RBRACE_TOK  
                            |  PARA_TOK LBRACE_TOK error RBRACE_TOK  SEM_TOK
                            ;
list_of_parameter_assignments : ordered_parameter_assignment_list
                               | named_parameter_assignment_list
                               ;

ordered_parameter_assignment_list:ordered_parameter_assignment {}
								 | ordered_parameter_assignment_list COMMA_TOK ordered_parameter_assignment 
                                 ;

ordered_parameter_assignment : expression
                             ;

 named_parameter_assignment_list :  named_parameter_assignment { }
                                 |  named_parameter_assignment_list COMMA_TOK named_parameter_assignment 
                                 ;
                             

named_parameter_assignment : DOT_TOK identifier LBRACE_TOK  expression  RBRACE_TOK {vbufreset();}
                           | DOT_TOK identifier LBRACE_TOK    RBRACE_TOK { vbufreset();}
                           ;


module_instance : identifier11  LBRACE_TOK  list_of_port_connections  RBRACE_TOK {vbufreset(); currVerilogType=0;} 
| identifier11  LBRACE_TOK error  RBRACE_TOK {vbufreset(); currVerilogType=0;}  
| identifier11 LBRACE_TOK   RBRACE_TOK                        {vbufreset(); currVerilogType=0;} 
;

identifier11:identifier xrange { 
  QCString secName($<cstr>0);
  QCString firstName($<cstr>1);;
  //fprintf(stderr, "identifier11: identifier '%s' xrange '%s'\n", $<cstr>1, $<cstr>0);
  if(moduleParamName.isEmpty()){
    moduleParamName=secName;
    moduleLine=c_lloc.last_line;
  }
  parseModuleInst(firstName,moduleParamName);
  moduleParamName.resize(0);
  if(parseCode){
    currVerilogType=VerilogDocGen::COMPONENT;
    vbufreset();
  }
}
// | identifier range;        
;

				 
list_of_port_connections : ordered_port_connection_list 
                         | named_port_connection_list 
						 ;
						 
ordered_port_connection_list : ordered_port_connection
                             | ordered_port_connection_list COMMA_TOK ordered_port_connection
							 ;

ordered_port_connection : attribute_instance  expression { vbufreset(); }
                       
						;
							 
named_port_connection_list : named_port_connection
                           | named_port_connection_list COMMA_TOK named_port_connection
						   ;

named_port_connection : attribute_instance named_parameter_assignment
                      ;

 

//------------------------------------------------------------------------------------------------------
//---------------------------- A.4.2 Generated instantiation  --------------------------------------------
//-----------------------------------------------------------------------------------------------------
//generated_instantiation ::= generate { generate_item } endgenerate

generated_instantiation :  GENERATE_TOK {CurrState=VerilogDocGen::STATE_GENERATE;generateItem=true;}  generate_item_list  ENDGENERATE_TOK {CurrState=0;generateItem=false;}
            					              |  GENERATE_TOK error  ENDGENERATE_TOK {CurrState=0;generateItem=false;}
            					              ;
            					              
generate_item_list :generate_item
                   | generate_item_list generate_item
				   ;
   
   
generate_item_or_null : generate_item   
                      | SEM_TOK
			           ;		  


generate_item : generate_conditional_statement{vbufreset();} 
              | generate_case_statement       {vbufreset();} 
              | generate_loop_statement       {vbufreset();}       
              | generate_block                {vbufreset();} 
              | module_or_generate_item       {vbufreset();}
			  ;

generate_conditional_statement  :  IF_TOK LBRACE_TOK  expression RBRACE_TOK generate_item_or_null 
                                 |   IF_TOK LBRACE_TOK  expression RBRACE_TOK generate_item_or_null  ELSE_TOK  generate_item_or_null 
     						     ;

generate_case_statement :CASE_TOK  LBRACE_TOK  expression RBRACE_TOK  genvar_module_case_item_list  ENDCASE_TOK    
							   ;

genvar_module_case_item_list  :  genvar_case_item  
							  |  genvar_module_case_item_list  genvar_case_item 
							  ;

genvar_case_item   :  expression_list COLON_TOK  generate_item_or_null
                   | DEFAULT_TOK   COLON_TOK  generate_item_or_null
                   | DEFAULT_TOK   generate_item_or_null
				   ;


generate_loop_statement  : FOR_TOK  LBRACE_TOK  genvar_assignment SEM_TOK  expression SEM_TOK  genvar_assignment  RBRACE_TOK BEGIN_TOK COLON_TOK identifier  generate_item_list  END_TOK 
                         ;

genvar_assignment : identifier EQU_TOK expression
                  ;

generate_block  :  BEGIN_TOK COLON_TOK identifier  generate_item_list  END_TOK  
                             |  BEGIN_TOK generate_item_list END_TOK
                             |  BEGIN_TOK error END_TOK { vbufreset();}
                             |  BEGIN_TOK COLON_TOK identifier error END_TOK { vbufreset();}
                             ;


//------------------------------------------------------------------------------------------------------
//---------------------------- A.5.1 UDP declaration  --------------------------------------------
//-----------------------------------------------------------------------------------------------------

udp_declaration : attribute_instance  PRIMITIVE_TOK name_of_udp  LBRACE_TOK  udp_port_list RBRACE_TOK SEM_TOK
                  udp_port_declaration_list udp_body ENDPRIMITIVE_TOK{vbufreset();currentVerilog=0;}
                 | attribute_instance  PRIMITIVE_TOK name_of_udp LBRACE_TOK udp_declaration_port_list RBRACE_TOK SEM_TOK
                  udp_port_declaration_list udp_body ENDPRIMITIVE_TOK
               //| PRIMITIVE_TOK error ENDPRIMITIVE_TOK {vbufreset();currentVerilog=0;}
				;

name_of_udp:        identifier { if(!parseCode) { 
							               //  printf("\n  name_of_mod [%s] [%d]--\n",getVerilogString(),getVerilogLine());
                                            lastModule=VerilogDocGen::makeNewEntry("",Entry::CLASS_SEC,VerilogDocGen::MODULE);
                                             currentVerilog=lastModule;
                                             currentVerilog->protection=Private;
					                        //  currentVerilog->stat=TRUE;
					                         parseModule();
							                 CurrState=VerilogDocGen::STATE_MODULE;

										    }
                                            else {
											      parseModule();
                                              //    currVerilogType=VerilogDocGen::MODULE;
												  }
						        vbufreset();
							 }
                         ;
 //------------------------------------------------------------------------------------------------------
//---------------------------- A.5.2 UDP Ports  --------------------------------------------
//-----------------------------------------------------------------------------------------------------


udp_port_list : identifier                            {parseListOfPorts();vbufreset();}
              | udp_port_list COMMA_TOK  identifier {parseListOfPorts();vbufreset();}
			  ;
udp_declaration_port_list : udp_output_declaration COMMA_TOK  udp_input_declaration_list
                          ;

udp_input_declaration_list:udp_input_declaration
                           | udp_input_declaration_list COMMA_TOK udp_input_declaration
                           | udp_input_declaration_list COMMA_TOK identifier 
							;

udp_port_declaration_list:udp_port_declaration
                         | udp_port_declaration_list  udp_port_declaration
						 ;  

udp_port_declaration : udp_output_declaration SEM_TOK
                     | udp_input_declaration SEM_TOK
                     | udp_reg_declaration SEM_TOK
                 	
					 | udp_port_declaration SEM_TOK
					  ;

udp_output_declaration : attribute_instance  OUTPUT_TOK identifier                                    { currVerilogType=VerilogDocGen::OUTPUT;if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
                       | attribute_instance  OUTPUT_TOK REG_TOK identifier                          { currVerilogType=VerilogDocGen::OUTPUT;if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
                       | attribute_instance  OUTPUT_TOK REG_TOK identifier  EQU_TOK expression    { currVerilogType=VerilogDocGen::OUTPUT;if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
                       | udp_output_declaration COMMA_TOK identifier                                  { currVerilogType=VerilogDocGen::OUTPUT;if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
					    ;

udp_input_declaration : attribute_instance  INPUT_TOK identifier        { currVerilogType=VerilogDocGen::INPUT;if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
                       | udp_input_declaration COMMA_TOK identifier     { currVerilogType=VerilogDocGen::INPUT;if(!parseCode)parsePortDir(currentVerilog,3);vbufreset();}
                       ;
udp_reg_declaration :  attribute_instance  REG_TOK identifier              {if(!parseCode) parseReg(currentVerilog);vbufreset();} 
                     | udp_reg_declaration COMMA_TOK identifier            {if(!parseCode) parseReg(currentVerilog);vbufreset();} 
					 ;
//------------------------------------------------------------------------------------------------------
//----------------------------5.3 body  --------------------------------------------
//-----------------------------------------------------------------------------------------------------

udp_body :  combinational_body 
          // | sequential_body
           ;

combinational_body : TABLE_TOK combinational_entry_list ENDTABLE_TOK                         { vbufreset();} 
                    |  TABLE_TOK error ENDTABLE_TOK                                          { vbufreset();} 
				    | udp_initial_statement  TABLE_TOK combinational_entry_list ENDTABLE_TOK { vbufreset();}
				   | udp_initial_statement  TABLE_TOK error ENDTABLE_TOK { vbufreset();}
				
					;

combinational_entry_list:combinational_entry
                        | combinational_entry_list combinational_entry
                         ;

combinational_entry : edge_input_list COLON_TOK  output_symbol SEM_TOK
                    | edge_input_list COLON_TOK current_state COLON_TOK next_state SEM_TOK
					;



udp_initial_statement : INITIAL_TOK identifier EQU_TOK init_val SEM_TOK { vbufreset(); }
                      | INITIAL_TOK error SEM_TOK                         { vbufreset(); }
					   ;

init_val : DIGIT_TOK { identVerilog+=$<cstr>1;writeDigit(); } 
         ;

				   
edge_input_list :edge_indicator
                | level_symbol
                | edge_input_list edge_indicator 
			    | edge_input_list level_symbol
				; 

edge_indicator : LBRACE_TOK level_symbol RBRACE_TOK
               | LBRACE_TOK level_symbol level_symbol RBRACE_TOK
			   |  edge_indicator LBRACE_TOK level_symbol RBRACE_TOK
			  // | error RBRACE_TOK
			   ;

current_state :level_symbol
              ; 
next_state : output_symbol 
           | MINUS_TOK
		    ;

output_symbol : level_symbol


level_symbol : DIGIT_TOK { identVerilog+=$<cstr>1;writeDigit(); } 
             | QUESTION_TOK
			 | MULT_TOK
			 | LETTER_TOK 

			 ;

//------------------------------------------------------------------------------------------------------
//----------------------------A.5.4 UDP instantiation  --------------------------------------------
//-----------------------------------------------------------------------------------------------------

udp_instantiation : identifier drive_strength  delay2  udp_instance_list SEM_TOK
                  | identifier drive_strength  udp_instance_list SEM_TOK
                  | identifier   udp_instance_list SEM_TOK
				  ;

udp_instance_list: udp_instance
                 | udp_instance_list COMMA_TOK udp_instance
				 ;

udp_instance : name_of_instance LBRACE_TOK output_terminal COMMA_TOK expression_list RBRACE_TOK
             | LBRACE_TOK output_terminal COMMA_TOK expression_list RBRACE_TOK
			 ;

name_of_instance :identifier11 // xrange 
                 //| identifier
				 ;

//------------------------------------------------------------------------------------------------------
//----------------------------A.6 Behavioral statements --------------------------------------------
//-----------------------------------------------------------------------------------------------------

continuous_assign : ASSIGN_TOK  drive_strength  delay3  list_of_net_assignments SEM_TOK
                  | ASSIGN_TOK    delay3  list_of_net_assignments SEM_TOK
				  | ASSIGN_TOK     list_of_net_assignments SEM_TOK
				  | ASSIGN_TOK  drive_strength  list_of_net_assignments SEM_TOK              
				  ;

list_of_net_assignments : net_assignment 
                        | list_of_net_assignments COMMA_TOK net_assignment
						;

net_assignment : net_lvalue EQU_TOK expression
               ;

initial_construct : INITIAL_TOK statement { vbufreset(); }
                   |INITIAL_TOK error END_TOK  { vbufreset();  }
				   ;

always_construct : ALWAYS_TOK {
                               currVerilogType=VerilogDocGen::ALWAYS;
                               prevName.resize(0);
                     		   } statement {
                                            if(!parseCode && currentFunctionVerilog)
											 {
											  currentFunctionVerilog->endBodyLine=getVerilogEndLine();
											  if( currentFunctionVerilog->endBodyLine<currentFunctionVerilog->startLine || c_lloc.first_line>currentFunctionVerilog->endBodyLine ) // awlays without end
											   currentFunctionVerilog->endBodyLine=c_lloc.first_line;
											  currVerilogType=0;
											  }
											   vbufreset();}
                  | always_construct error END_TOK { vbufreset();currVerilogType=0;}
				  ; 


blocking_assignment : net_lvalue EQU_TOK delay_or_event_control  expression
                    | net_lvalue EQU_TOK   expression
					| net_lvalue EQU_TOK  delay_or_event_control
					| blocking_assignment error {vbufreset();}
					;

nonblocking_assignment : net_lvalue GT_TOK EQU_TOK delay_or_event_control  expression
                    | net_lvalue GT_TOK EQU_TOK   expression
					| net_lvalue GT_TOK EQU_TOK  delay_or_event_control
					| nonblocking_assignment error {vbufreset();}
					;

 //------------------------------------------------------------------------------------------------------
//----------------------------A.6.2 Procedureal blocks and assignments--------------------------------------------
//-----------------------------------------------------------------------------------------------------

procedural_continuous_assignments : ASSIGN_TOK variable_assignment
                                   | DEASSIGN_TOK net_lvalue
                                   | FORCE_TOK net_assignment
                                   | RELEASE_TOK net_lvalue
                                   ;

function_blocking_assignment : net_lvalue EQU_TOK expression
                             ;


function_statement_or_null : function_statement
                           |  attribute_instance  SEM_TOK
						    ;


//------------------------------------------------------------------------------------------------------
//----------------------------A.6.3 Parallel and sequential blocks--------------------------------------------
//-----------------------------------------------------------------------------------------------------

function_seq_block : BEGIN_TOK statement_list  END_TOK
                   | BEGIN_TOK COLON_TOK identifier block_item_declaration_list  statement_list  END_TOK
				   | BEGIN_TOK COLON_TOK identifier function_statement_list  END_TOK
				   | BEGIN_TOK block_item_declaration_list  statement_list  END_TOK
				   | BEGIN_TOK END_TOK
				   ;



function_statement_list:function_statement
                       | function_statement_list function_statement
					    ;
						
variable_assignment : net_lvalue EQU_TOK expression
                    ;  

par_block : FORK_TOK  statement_list  JOIN_TOK
          | FORK_TOK COLON_TOK identifier block_item_declaration_list statement_list  JOIN_TOK
		  | FORK_TOK COLON_TOK identifier statement_list  JOIN_TOK
		  | FORK_TOK JOIN_TOK
		  | FORK_TOK COLON_TOK error JOIN_TOK
          | FORK_TOK error JOIN_TOK 
		   ;
		   

seq_block : BEGIN_TOK 
            {if(!parseCode && currVerilogType==VerilogDocGen::ALWAYS)parseAlways(true);} // alway without ()
             statement_list  END_TOK
          | BEGIN_TOK  always_label    block_item_declaration_list statement_list  END_TOK
		  | BEGIN_TOK   always_label    statement_list  END_TOK
		  | BEGIN_TOK  END_TOK
		  | BEGIN_TOK   always_label  END_TOK
		  | BEGIN_TOK error END_TOK
		  ;

 always_label:     COLON_TOK identifier  {
                                            if(!parseCode){
                                             if(currentFunctionVerilog && currentFunctionVerilog->spec==VerilogDocGen::ALWAYS){
                                             VerilogDocGen::adjustMemberName(prevName); 
                                             currentFunctionVerilog->name=prevName;
                                            }
                                          }
                                         }

statement_list:statement
              | statement_list statement
			  ;

//------------------------------------------------------------------------------------------------------
//----------------------------A.6.4 Statements --------------------------------------------
//-----------------------------------------------------------------------------------------------------


statement : attribute_instance blocking_assignment SEM_TOK
          | attribute_instance  case_statement
          |  attribute_instance  conditional_statement
          |  attribute_instance  disable_statement
          |  attribute_instance  event_trigger
          |  attribute_instance  loop_statement
          |  attribute_instance  nonblocking_assignment SEM_TOK 
          |  attribute_instance  par_block
          |  attribute_instance  procedural_continuous_assignments SEM_TOK
          |  attribute_instance  procedural_timing_control_statement 
          |  attribute_instance  seq_block {vbufreset();} 
          |  attribute_instance  system_task_enable
          |  attribute_instance  wait_statement 
		   ;

statement_or_null  : statement
                  |   SEM_TOK
  			      ;
				  

function_statement : attribute_instance  function_blocking_assignment SEM_TOK
                   |  attribute_instance  function_case_statement
                   |  attribute_instance  function_conditional_statement
                   |  attribute_instance  function_loop_statement
                   |  attribute_instance  function_seq_block
                   |  attribute_instance  disable_statement
                   |  attribute_instance  system_task_enable
                   ;

function_case_statement:case_statement
                       ;
//------------------------------------------------------------------------------------------------------
//----------------------------A.6.5 Timing control statements--------------------------------------------
//-----------------------------------------------------------------------------------------------------

delay_control: PARA_TOK DIGIT_TOK 
  	         | PARA_TOK LETTER_TOK
         	 | PARA_TOK LBRACE_TOK mintypemax_expression RBRACE_TOK {vbufreset();}
             ;

delay_or_event_control : delay_control
                       | event_control 
                       | REPEAT_TOK LBRACE_TOK expression {currVerilogType=0;}  RBRACE_TOK  event_control {currVerilogType=0;}
                       ;

disable_statement : DISABLE_TOK identifier SEM_TOK
     			  ;

event_control : AT_TOK  identifier                                     { parseAlways(); vbufreset();currVerilogType=0;} 
	          | AT_TOK LBRACE_TOK event_expression_list RBRACE_TOK { parseAlways(); vbufreset();currVerilogType=0;}			 
              | AT_TOK MULT_TOK                                      { parseAlways(); vbufreset();currVerilogType=0;}	
              | AT_TOK LBRACE_TOK MULT_TOK RBRACE_TOK            { parseAlways(); vbufreset();currVerilogType=0;}	
              | AT_TOK ATL_TOK  RBRACE_TOK            { parseAlways(); vbufreset();currVerilogType=0;}				
			  ;
			  
event_trigger : MINUS_TOK LT_TOK identifier SEM_TOK
              ;

event_expression : expression
                 | POSEDGE_TOK expression
                 | NEGEDGE_TOK expression
                 ;

event_expression_list : event_expression 
                      | event_expression_list COMMA_TOK event_expression 
					  | event_expression_list GATE_TOK event_expression 
                       ; 

procedural_timing_control_statement : delay_or_event_control statement_or_null
                                    ;
wait_statement : WAIT_TOK LBRACE_TOK expression RBRACE_TOK statement_or_null

//------------------------------------------------------------------------------------------------------
//----------------------------A.6.6 Conditional statements--------------------------------------------
//-----------------------------------------------------------------------------------------------------

conditional_statement : IF_TOK LBRACE_TOK expression RBRACE_TOK statement_or_null
	                   | IF_TOK LBRACE_TOK expression RBRACE_TOK statement_or_null ELSE_TOK statement_or_null
	                   | IF_TOK LBRACE_TOK expression RBRACE_TOK error ELSE_TOK statement_or_null
	                   | IF_TOK LBRACE_TOK error RBRACE_TOK 
	                   ;

function_conditional_statement :IF_TOK LBRACE_TOK expression RBRACE_TOK function_statement_or_null
	                           | IF_TOK LBRACE_TOK expression RBRACE_TOK function_statement_or_null ELSE_TOK function_statement_or_null
	                           | IF_TOK LBRACE_TOK error RBRACE_TOK
	                           ;
					  
 


case_statement:	CASE_TOK LBRACE_TOK expression RBRACE_TOK case_item_list ENDCASE_TOK
	           |  CASE_TOK LBRACE_TOK expression RBRACE_TOK error ENDCASE_TOK { vbufreset();}
			   | CASEZ_TOK LBRACE_TOK expression RBRACE_TOK case_item_list ENDCASE_TOK
	           | CASEZ_TOK error ENDCASE_TOK { vbufreset();}
	           | CASEX_TOK LBRACE_TOK expression RBRACE_TOK case_item_list ENDCASE_TOK
	           | CASEX_TOK error ENDCASE_TOK { vbufreset();}
	           ;


case_item_list: case_item
              | case_item_list case_item
              ;


case_item :expression_list  COLON_TOK statement_or_null
	      | DEFAULT_TOK COLON_TOK  statement_or_null
	      | DEFAULT_TOK statement_or_null
          ;

//------------------------------------------------------------------------------------------------------
//----------------------------A.6.8 Looping statements--------------------------------------------
//-----------------------------------------------------------------------------------------------------

function_loop_statement : FOREVER_TOK function_statement
                       | REPEAT_TOK LBRACE_TOK expression RBRACE_TOK function_statement
                       | WHILE_TOK LBRACE_TOK expression RBRACE_TOK function_statement
                       | FOR_TOK LBRACE_TOK variable_assignment SEM_TOK expression SEM_TOK variable_assignment RBRACE_TOK function_statement
                       ;


loop_statement : FOREVER_TOK statement
               | REPEAT_TOK LBRACE_TOK expression RBRACE_TOK statement
               | WHILE_TOK LBRACE_TOK expression RBRACE_TOK statement
               | FOR_TOK LBRACE_TOK variable_assignment SEM_TOK expression SEM_TOK variable_assignment RBRACE_TOK statement
               ;


//------------------------------------------------------------------------------------------------------
//----------------------------A.6.9 Task enable statements--------------------------------------------
//-----------------------------------------------------------------------------------------------------

system_task_enable : simple_identifier  LBRACE_TOK expression_list_null  RBRACE_TOK SEM_TOK
                   | simple_identifier  LBRACE_TOK error  RBRACE_TOK SEM_TOK
				   | simple_identifier SEM_TOK
				   ;

expression_list_null:  expression 
   | expression_list_null COMMA_TOK expression
   | expression_list_null COMMA_TOK
   | COMMA_TOK
   ;

//------------------------------------------------------------------------------------------------------
//----------------------------A.7.1 Specify block declaration -------------------------------------------
//-----------------------------------------------------------------------------------------------------

specify_block:SPECIFY_TOK specify_item_list ENDSPECIFY_TOK
             | SPECIFY_TOK  ENDSPECIFY_TOK { vbufreset(); }
			 | SPECIFY_TOK error ENDSPECIFY_TOK  { vbufreset(); }
			  ;


specify_item_list:specify_item { vbufreset(); }
              | specify_item_list specify_item { vbufreset(); }
              ;


specify_item: specparam_declaration {vbufreset();}
	        | path_declaration {vbufreset();}
	        | system_timing_check {vbufreset();}
	        | pulsestyle_declaration {vbufreset();}
            | showcancelled_declaration {vbufreset();}
            ;
			

pulsestyle_declaration : PULSEON_DETECT_TOK list_of_path_outputs SEM_TOK
                       | PULSEONE_EVENT_TOK list_of_path_outputs SEM_TOK
                       | PULSEONE_EVENT_TOK error SEM_TOK
					   ;


showcancelled_declaration : SHOWCANCEL_TOK list_of_path_outputs SEM_TOK
                          | NOSHOWCANCEL_TOK  list_of_path_outputs SEM_TOK
                          | NOSHOWCANCEL_TOK error SEM_TOK
						  ;

 //------------------------------------------------------------------------------------------------------
//----------------------------A.7.1 Specify Task declaration -------------------------------------------
//-----------------------------------------------------------------------------------------------------

path_declaration : simple_path_declaration SEM_TOK
                 | edge_sensitive_path_declaration SEM_TOK
                 | state_dependent_path_declaration SEM_TOK
                 ;


simple_path_declaration : parallel_path_description EQU_TOK path_delay_value
                       // | full_path_description EQU_TOK path_delay_value
                         ;


parallel_path_description : LBRACE_TOK specify_input_terminal_descriptor  EQU_TOK LT_TOK specify_input_terminal_descriptor RBRACE_TOK
						  | LBRACE_TOK list_of_path_inputs  connection list_of_path_outputs RBRACE_TOK
                          | LBRACE_TOK list_of_path_inputs    MULT_TOK LT_TOK list_of_path_outputs RBRACE_TOK
					      ;

list_of_path_inputs : specify_input_terminal_descriptor
                    | list_of_path_inputs COMMA_TOK specify_input_terminal_descriptor 
                    ;

list_of_path_outputs : list_of_path_inputs 
                     ;
          
connection:polarity_operator  EQU_TOK LT_TOK
   | polarity_operator  MULT_TOK LT_TOK 
   ;

//specify_output_terminal_descriptor
//                    | list_of_path_output COMMA_TOK specify_output_terminal_descriptor 
//                    ;
//------------------------------------------------------------------------------------------------------
//----------------------------A.7.3 Specify block terminals -------------------------------------------
//-----------------------------------------------------------------------------------------------------

specify_input_terminal_descriptor : identifier
                                  | identifier LBRACKET_TOK range_expression RBRACKET_TOK 
								  | identifier LBRACKET_TOK expression RBRACKET_TOK 
								  ;


path_delay_value : list_of_path_delay_expressions
                  | LBRACE_TOK list_of_path_delay_expressions RBRACE_TOK
                 ;


list_of_path_delay_expressions:path_delay_expression
	            | LBRACE_TOK path_delay_expression COMMA_TOK path_delay_expression RBRACE_TOK
	            | LBRACE_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression RBRACE_TOK
	            | LBRACE_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression RBRACE_TOK
	            | LBRACE_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression COMMA_TOK path_delay_expression RBRACE_TOK
	            ;

//------------------------------------------------------------------------------------------------------
//----------------------------A.7.4 Specify path delays -------------------------------------------
//-----------------------------------------------------------------------------------------------------


path_delay_expression:mintypemax_expression


edge_sensitive_path_declaration : parallel_edge_sensitive_path_description EQU_TOK path_delay_value
                                | full_edge_sensitive_path_description EQU_TOK path_delay_value
                                ;


parallel_edge_sensitive_path_description : LBRACE_TOK  edge_identifier  specify_input_terminal_descriptor EQU_TOK LT_TOK example
                                          |  LBRACE_TOK  specify_input_terminal_descriptor EQU_TOK LT_TOK example                                           
										   ;


full_edge_sensitive_path_description : LBRACE_TOK edge_identifier  list_of_path_inputs MULT_TOK LT_TOK
                                        list_of_path_outputs  pol_op  COLON_TOK data_source_expression RBRACE_TOK
                                     | LBRACE_TOK   list_of_path_inputs MULT_TOK LT_TOK
                                        list_of_path_outputs  pol_op  COLON_TOK data_source_expression RBRACE_TOK
                                      ;



example:   specify_input_terminal_descriptor  pol_op  COLON_TOK data_source_expression RBRACE_TOK
       |  LBRACE_TOK specify_input_terminal_descriptor  pol_op  COLON_TOK data_source_expression RBRACE_TOK RBRACE_TOK // rule for altera
	   ;                               


data_source_expression :  expression
                        ;
edge_identifier :   POSEDGE_TOK
	            | NEGEDGE_TOK
                ;


state_dependent_path_declaration : IF_TOK LBRACE_TOK expression RBRACE_TOK simple_path_declaration
                                 | IF_TOK LBRACE_TOK  expression RBRACE_TOK edge_sensitive_path_declaration
                                 | IFNONE_TOK simple_path_declaration
                                 ;


polarity_operator :  pol_op
                   ;


//------------------------------------------------------------------------------------------------------
//----------------------------A.7.5.1 System timing check commands -------------------------------------------
//-----------------------------------------------------------------------------------------------------


system_timing_check :setup_timing_check
                    | hold_timing_check
                    | setuphold_timing_check
                    | recovery_timing_check
                    | removal_timing_check
                    | skew_timing_check
                    | period_timing_check 
                    | width_timing_check
                    | nochange_timing_check		 
					| recrem_timing_check
                    | fullskew_timing_check 
					| timingskew_timing_check 				    
					;


fullskew_timing_check : FULLSKEW_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit COMMA_TOK notify_register_list  RBRACE_TOK SEM_TOK
                     | FULLSKEW_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit RBRACE_TOK SEM_TOK
                     ;

timingskew_timing_check : TIMESKEW_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit COMMA_TOK notify_register_list  RBRACE_TOK SEM_TOK
                     | TIMESKEW_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit RBRACE_TOK SEM_TOK
                     ;


recrem_timing_check  : RECREM_TOK  LBRACE_TOK timing_check_event  COMMA_TOK  timing_check_event  COMMA_TOK  timing_check_limit  COMMA_TOK  timing_check_limit  COMMA_TOK notify_register_list RBRACE_TOK SEM_TOK
                        | RECREM_TOK  LBRACE_TOK timing_check_event  COMMA_TOK  timing_check_event  COMMA_TOK  timing_check_limit  COMMA_TOK  timing_check_limit  RBRACE_TOK SEM_TOK
                        ; 
 

setup_timing_check : DSETUP_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit COMMA_TOK notify_register_list  RBRACE_TOK SEM_TOK
                   | DSETUP_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit RBRACE_TOK SEM_TOK
                   | DSETUP_TOK LBRACE_TOK error RBRACE_TOK
				   ;

hold_timing_check : DHOLD_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit COMMA_TOK notify_register_list RBRACE_TOK SEM_TOK
                   | DHOLD_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit RBRACE_TOK SEM_TOK
                   | DHOLD_TOK error SEM_TOK
				   ;


setuphold_timing_check  : DSETUPHOLD_TOK  LBRACE_TOK timing_check_event  COMMA_TOK  timing_check_event  COMMA_TOK  timing_check_limit  COMMA_TOK  timing_check_limit  COMMA_TOK notify_register_list RBRACE_TOK SEM_TOK
                        | DSETUPHOLD_TOK  LBRACE_TOK timing_check_event  COMMA_TOK  timing_check_event  COMMA_TOK  timing_check_limit  COMMA_TOK  timing_check_limit  RBRACE_TOK SEM_TOK
                        ; 

recovery_timing_check:DRECOVERY_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit COMMA_TOK notify_register_list  RBRACE_TOK SEM_TOK
                     | DRECOVERY_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit RBRACE_TOK SEM_TOK
                     ;
removal_timing_check: REMOVAL_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit COMMA_TOK notify_register_list  RBRACE_TOK SEM_TOK
                     | REMOVAL_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit RBRACE_TOK SEM_TOK
                     ;


skew_timing_check : DSKEW_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit COMMA_TOK notify_register_list  RBRACE_TOK SEM_TOK
                     | DSKEW_TOK LBRACE_TOK data_event COMMA_TOK reference_event COMMA_TOK timing_check_limit RBRACE_TOK SEM_TOK
                     ;

 nochange_timing_check	:  NOCHANGE_TOK  LBRACE_TOK timing_check_event COMMA_TOK timing_check_event COMMA_TOK mintypemax_expression COMMA_TOK mintypemax_expression RBRACE_TOK SEM_TOK
	                    | NOCHANGE_TOK   LBRACE_TOK timing_check_event COMMA_TOK timing_check_event COMMA_TOK mintypemax_expression COMMA_TOK mintypemax_expression COMMA_TOK notify_register_list RBRACE_TOK SEM_TOK
	                    ;

width_timing_check :  DWIDTH_TOK  LBRACE_TOK controlled_timing_check_event COMMA_TOK timing_check_limit COMMA_TOK expression COMMA_TOK notify_register_list RBRACE_TOK SEM_TOK
                     |  DWIDTH_TOK  LBRACE_TOK controlled_timing_check_event COMMA_TOK timing_check_limit RBRACE_TOK SEM_TOK

					 ;

period_timing_check :DPERIOD_TOK   LBRACE_TOK controlled_timing_check_event COMMA_TOK timing_check_limit RBRACE_TOK SEM_TOK
                     | DPERIOD_TOK  LBRACE_TOK controlled_timing_check_event COMMA_TOK timing_check_limit COMMA_TOK notify_register_list RBRACE_TOK SEM_TOK
                     ;

notify_register_list:notify_register
                    | notify_register_list COMMA_TOK notify_register
					;

 notify_register:expression

                   

//------------------------------------------------------------------------------------------------------
//----------------------------A.7.5.2 System timing check command arguments  -------------------------------------------
//-----------------------------------------------------------------------------------------------------

timing_check_limit :  expression
                   ;
data_event : timing_check_event
           ;

reference_event : timing_check_event
           ;

timing_check_event :timing_check_event_control specify_terminal_descriptor AAAND_TOK timing_check_condition
                    | timing_check_event_control specify_terminal_descriptor 
                    | specify_terminal_descriptor AAAND_TOK timing_check_condition
                    | specify_terminal_descriptor 
					 ;

controlled_timing_check_event:timing_check_event
                            
                             ;

timing_check_event_control :POSEDGE_TOK
	                       | NEGEDGE_TOK
                           | edge_control_specifier
                           ;

edge_control_specifier :EDGE_TOK  LBRACKET_TOK edge_descriptor_list RBRACKET_TOK
                       | error RBRACKET_TOK
					   ;

edge_descriptor : DIGIT_TOK DIGIT_TOK 
	             | DIGIT_TOK LETTER_TOK
				 | LETTER_TOK DIGIT_TOK
                 ;

edge_descriptor_list :  edge_descriptor
	             | edge_descriptor_list COMMA_TOK edge_descriptor
				 ;

specify_terminal_descriptor : specify_input_terminal_descriptor 
                            ;


timing_check_condition : mintypemax_expression //scalar_timing_check_condition
	                     ;

//------------------------------------------------------------------------------------------------------
//----------------------------A.8.1 Concatenations  -------------------------------------------
//-----------------------------------------------------------------------------------------------------


concatenation : LRAM_TOK expression_list RRAM_TOK
              | LRAM_TOK expression  LRAM_TOK expression_list RRAM_TOK RRAM_TOK
		                            ;
//multiple_concatenation :   concatenation 
//                        ; 

net_concatenation : LRAM_TOK net_concatenation_value_list RRAM_TOK
                  ;
net_concatenation_value_list: net_concatenation_value
                            | net_concatenation_value_list COMMA_TOK net_concatenation_value
							 ;
							 
net_concatenation_value : identifier LBRACKET_TOK range_expression RBRACKET_TOK
                        | identifier LBRACKET_TOK expression RBRACKET_TOK
                        | identifier expression_bracket_list range_expression 
                        | net_concatenation
						| identifier						
                        ;
 

      //------------------------------------------------------------------------------------------------------
//----------------------------A.8.2 Concatenations  -------------------------------------------
//-----------------------------------------------------------------------------------------------------

  
function_call :  LBRACE_TOK  expression_list RBRACE_TOK
			  | attribute_instance11 LBRACE_TOK  expression_list RBRACE_TOK
			  ;


//------------------------------------------------------------------------------------------------------
//----------------------------A.8.3 Expressions  -------------------------------------------
//-----------------------------------------------------------------------------------------------------

expression_bracket_list: LBRACKET_TOK expression RBRACKET_TOK
                       | expression_bracket_list LBRACKET_TOK expression RBRACKET_TOK
  					   
					   ; 


dimension_constant_expression :expression
                              ;


range_expression :  expression COLON_TOK lsb_constant_expression
                 | expression PLUS_TOK COLON_TOK width_constant_expression
                 | expression MINUS_TOK COLON_TOK width_constant_expression
                 ;

expression_list: expression
               | expression_list COMMA_TOK expression

                          ;
//------------------------------------------------------------------------------------------------------
//----------------------------A.8.4 Primaries  -------------------------------------------
//-----------------------------------------------------------------------------------------------------


primary : simple_identifier  expression_bracket_list
		| simple_identifier LBRACKET_TOK range_expression RBRACKET_TOK 
        | simple_identifier  expression_bracket_list LBRACKET_TOK range_expression RBRACKET_TOK     
		| simple_identifier
		| simple_identifier function_call
		| LBRACE_TOK mintypemax_expression RBRACE_TOK 
        | concatenation
       // | multiple_concatenation
		| number
		;


 unprim:   primary
  		   | STRING_TOK
		   | unary_operator primary
           | unary_operator attribute_instance11 primary	  
		   ;

expression : unprim
           | expression binary_operator  unprim
	       | expression  binary_operator attribute_instance11  unprim
		   | expression QUESTION_TOK expression COLON_TOK unprim 
		   ; 

mintypemax_expression : expression
                      | expression COLON_TOK expression COLON_TOK mintypemax_expression 
                       ;

lsb_constant_expression :expression
                        ;
msb_constant_expression :expression
                        ; 
width_constant_expression :expression

//------------------------------------------------------------------------------------------------------
//----------------------------A.8.6 Operators  -------------------------------------------
//-----------------------------------------------------------------------------------------------------


unary_operator :  EXCLAMATION_TOK 
			   |  AND_TOK
			   |   NOT_TOK
			   |  SN_TOK
			   |  SN_TOK AND_TOK
			   |  SNNOT_TOK
			   |  OR_TOK
			   |  SN_TOK OR_TOK
			   |  pol_op
			   |  NOTSN_TOK 
		        ;


binary_operator : PERCENTAL_TOK
				| pol_op // PLUS_TOK
				//| MINUS_TOK
				| EQU_TOK EQU_TOK 
			    | EQU_TOK EQU_TOK EQU_TOK
			    | EXCLAMATION_TOK EQU_TOK
			    | EXCLAMATION_TOK EQU_TOK EQU_TOK
				| AAND_TOK
				| OOR_TOK
		        | LT_TOK
				| GT_TOK 
				| GT_TOK GT_TOK
				| GT_TOK EQU_TOK
				| LT_TOK EQU_TOK
				| LT_TOK LT_TOK
				| MULT_TOK
				| ENV_TOK
				| NOT_TOK
				| AND_TOK
				| OR_TOK
				| SN_TOK
				| SNNOT_TOK
	            | NOTSN_TOK 
                | MULT_TOK MULT_TOK      // vlog 2001
				| GT_TOK GT_TOK GT_TOK // vlog2001
				| LT_TOK LT_TOK LT_TOK // vlog2001
                ;


//------------------------------------------------------------------------------------------------------
//----------------------------A.8.5 Expression left-side values  -------------------------------------------
//-----------------------------------------------------------------------------------------------------

net_lvalue : identifier LBRACKET_TOK range_expression RBRACKET_TOK
           | identifier expression_bracket_list 
           | net_concatenation
           | simple_identifier
		   ;




 signed :  SIGNED_TOK
		;

pol_op:MINUS_TOK
      | PLUS_TOK
                 ;
				  

number : DIGIT_TOK { identVerilog+=$<cstr>1;writeDigit(); } 
	     | pol_op DIGIT_TOK  {if(parseCode) {writePrevVerilogWords(identVerilog);writeVerilogFont("vhdllogic",identVerilog.data());identVerilog.resize(0);}}
      ;



//------------------------------------------------------------------------------------------------------
//----------------------------A.9.1 Attributes  -------------------------------------------
//-----------------------------------------------------------------------------------------------------


     
attribute_instance11 : ATL_TOK attr_spec_list ATR_TOK  {vbufreset();}
	  |  ATL_TOK error ATR_TOK { vbufreset(); }
                   ;

attribute_instance : /* empty */
				   |  ATL_TOK attr_spec_list ATR_TOK { vbufreset(); }
				   |  ATL_TOK  error ATR_TOK  { vbufreset(); }
                   ;

attr_spec_list: attr_spec
              | attr_spec_list COMMA_TOK attr_spec
			  ;				   

attr_spec : identifier EQU_TOK expression
		  | identifier
		  ;

 simple_identifier : identifier 
          | simple_identifier DOT_TOK identifier	{
										 }               		  
		  ;

identifier:ident { parseString(); }


ident : LETTER_TOK  {
                    	//if(parseCode) 
						      identVerilog+=$<cstr>1; 
						  //    fprintf(stderr,"\n String: %s",identVerilog.data());
							 } //LETTER_TOK 
        | DOLLAR_TOK  ident {}  	
	  ;	





%%
//------ ------------------------------------------------------------------------------------------------

 Entry* getCurrVerilogEntry(){return current;}
 Entry* getCurrVerilog(){return currentVerilog; }
 QCString getCurrVerilogParsingClass(){return currVerilogClass; }

 void initVerilogParser(Entry* ee,bool pc){
  identVerilog.resize(0);
  currVerilogInst.resize(0);
  currVerilogClass.resize(0);
  prevDocEntryVerilog.reset();
  currentVerilog=0;
  generateItem=false;
  currentFunctionVerilog=0;
  parseCode=pc;
  briefString.resize(0);
  briefLine=0;
if(pc) return;
  current_rootVerilog=ee;
  lastModule=0;
  current=new Entry;
  VerilogDocGen::initEntry(current);
  current_rootVerilog->name=QCString("XXX"); // dummy name for root
}

 Entry* VerilogDocGen::makeNewEntry(char* name,int sec,int spec,int line,bool add){
 
  Entry *e=current;
 /*
  if(e->briefLine>0 && e->brief.data())
  {
    briefLine=line;
    briefString=e->brief;
  }

  if(line==briefLine && briefString.data())
  {
   e->brief=briefString;
   briefString.resize(0);
  }  
  */

 if(parseCode) // should not happen!
 assert(0);

if(add)
{ // features like 'include xxx or 'define xxx must not be inserted here
 if(lastModule)
    addSubEntry(lastModule,e); 
  else
    addSubEntry(current_rootVerilog,e); 
}
else
  addSubEntry(current_rootVerilog,e);

if(line){
  	  e->bodyLine=line;
      e->startLine=line;
  }else
   {
     e->bodyLine=getVerilogPrevLine();
     e->startLine=getVerilogPrevLine();
   }
   
  e->section=sec;
  e->spec=spec;
  e->name=name;
  e->name.stripPrefix("\\");// escaped_identifier ??

  current=new Entry;
  VerilogDocGen::initEntry(current);
  
  return e;
 }

void addSubEntry(Entry* root, Entry* e) {
 if(e==NULL || root==NULL) return;
  root->addSubEntry(e);
 } 




//-------------------------------------------------------------------------
  
// extracts module/primitive name

void parseModule(){
 
 QCString mod(getVerilogString());
 VhdlDocGen::deleteAllChars(mod,'\n');
 VhdlDocGen::deleteAllChars(mod,' ');
 VhdlDocGen::deleteAllChars(mod,';');
 VhdlDocGen::deleteAllChars(mod,'(');
 
 QRegExp reg("[^_a-zA-Z0-9$]");

 int ll=mod.find(reg);

 if(ll>-1){
//  char c=mod.at(ll);
  QCString val=mod.remove(ll,1);

 }

//if(mod.len>80)

 if(parseCode) {
 //generateVerilogClassOrGlobalLink(mod.data());
 currVerilogClass=mod;
 return;
 }
  currentVerilog->name=mod;
 }//parseModuleName


// extracts module instances [ module_name name,module_name #(...) name]

 void parseModuleInst(QCString& first, QCString& sec) {
 
   if(currVerilogType==VerilogDocGen::DEFPARAM ) return; //|| generateItem 



   VhdlDocGen::deleteAllChars(sec,'(');
   VhdlDocGen::deleteAllChars(sec,'\n');
   VhdlDocGen::deleteAllChars(sec,')');
   VhdlDocGen::deleteAllChars(sec,' ');
   VhdlDocGen::deleteAllChars(sec,',');
   VhdlDocGen::deleteAllChars(sec,';');
   QCString temp=sec;
   //while(sec.stripPrefix(" "));

   if(sec!=first && (sec.contains("#")==0))
     { 
       //QStringList ql=QStringList::split(first.data(),sec,false);
       int oo=sec.findRev(first.data());
       if(oo>0) 
	 sec=sec.left(oo);
     }
   /* XXX this seems to be the source of my misery, but what's it for? -EWA */
   /* else */
   /*   sec=getLastLetter(); */

   if(temp.contains("#"))
     { 
       int ii=temp.find("#");
       sec=temp.left(ii);
       while(sec.stripPrefix(" "));
     }


   if(parseCode){
     VhdlDocGen::deleteAllChars(sec,'\t');
     currVerilogInst=sec;
     return;
   }
   else {
     Entry* pTemp=VerilogDocGen::makeNewEntry(sec.data(),Entry::VARIABLE_SEC,VerilogDocGen::COMPONENT,moduleLine);
     pTemp->type=first;
     if(generateItem) 
       pTemp->args="[generate]";
     if(sec==first)return;
     if(currentVerilog)
       if(!findExtendsComponent(currentVerilog->extends,sec)){	
	 BaseInfo *bb=new BaseInfo(sec,Private,Normal);
	 assert(bb->name != NULL);
	 currentVerilog->extends->append(bb);
       }
   }
 }


void parseListOfPorts() {
 
  QCString type;

 QCString mod(getVerilogString());
 if(Config_getBool("HIDE_PORT")) return;
 VhdlDocGen::deleteAllChars(mod,' ');
 VhdlDocGen::deleteAllChars(mod,'\n');
 VhdlDocGen::deleteAllChars(mod,';');
 VhdlDocGen::deleteAllChars(mod,')');
 VhdlDocGen::deleteAllChars(mod,'(');
  QStringList ql=QStringList::split(",",mod,false);
  QCString name=ql[0].data();
if(!parseCode) {
  for(uint j=0;j<ql.count();j++) {
  QCString name=ql[j].data();
   int i=name.find('[');
  if(i > 0){
    type=mod.right(mod.length()-i);
    name=mod.left(i);
  }
  
 name.prepend(VhdlDocGen::getRecordNumber().data());
 Entry* pTemp=VerilogDocGen::makeNewEntry(name.data(),Entry::VARIABLE_SEC,VerilogDocGen::PORT,c_lloc.first_line);
  pTemp->type=type; 
   }
  return;
 }	

 }//parseListOfPorts



void parseReg(Entry* e){

// "reg"|"integer\real\event"|wire"|"tri"|"tri1"|"supply0"|"wand"|"triand"|"tri0"|"supply1"|"wor"|"trior"|"trireg"

static QCString prevType;
static QCString sigType;
static QRegExp qregg("[ \\[]");
QCString regType;
QCString qcs;

int p,l;
     

 if((generateItem || CurrState==VerilogDocGen::STATE_FUNCTION || CurrState==VerilogDocGen::STATE_TASK )) return;

QCString mod(getVerilogString());

int port_type=0;

VhdlDocGen::deleteAllChars(mod,'(');
VhdlDocGen::deleteAllChars(mod,')');
VhdlDocGen::deleteAllChars(mod,';');
VhdlDocGen::deleteAllChars(mod,'\n');
VhdlDocGen::deleteAllChars(mod,',');

if(mod.contains("="))
{
 int i=mod.find("=");
 //qcs=mod.right(mod.length()-i-1);
 VhdlDocGen::deleteAllChars(qcs,' ');
 mod=mod.left(i);
}
  
 mod=mod.simplifyWhiteSpace(); 
  
//while(mod.stripPrefix(" "));
  p=qregg.match(mod,0,&l);

 if(p>0){
  sigType=mod.left(p);
  prevType.resize(0);
  mod.stripPrefix(sigType.data());
  while(mod.stripPrefix(" "));
  if(!mod.stripPrefix("signed ")){
  if(mod.stripPrefix("signed["))
    {mod.prepend("[");sigType.append(" signed ");}
  if(mod.stripPrefix("scalared "))
   sigType.append(" scalared ");
  if(mod.stripPrefix("vectored "))
    sigType.append(" vectored ");
 }
// else
  
}

 
 while(mod.stripPrefix(" "));
 

VhdlDocGen::deleteAllChars(mod,' ');

  int i=mod.find(']');
  int h=mod.find('[');

  if(h==0){
  	prevType+=mod.left(i+1);
  	mod=mod.right(mod.length()-i-1);
  h=mod.find('[');
  }

  if(h > 0){
   if(port_type!=2){ 
	regType=mod.right(mod.length()-h);
    mod=mod.left(h);
   }
   else {
    int ii=mod.find('[');
	if(ii>0){
  	prevType=mod.mid(ii,mod.length());
   	mod=mod.left(ii);
   }
  }
 }

  QStringList ql=QStringList::split(",",mod,false);
 uint len=ql.count() ;
 for(uint j=0;j<len;j++) {
  QCString name=ql[j].data();
  name.prepend(VhdlDocGen::getRecordNumber().data());
 
  Entry* pTemp=VerilogDocGen::makeNewEntry(name.data(),Entry::VARIABLE_SEC,getVerilogPrevLine());
 // pTemp->type=prevType;
 
  if((prevType.isEmpty() && len==1) || (!regType.isEmpty() && len==1))
     pTemp->type=regType;
 else
  pTemp->args=regType;
    
  pTemp->args+=sigType+prevType; 
 // if(!prevType.isEmpty() && !regType.isEmpty())
 // pTemp->args+=prevType; 

 pTemp->args+=qcs;
  pTemp->spec=VerilogDocGen::SIGNAL;//currVerilogType;
  
  regType=prevType;
  if(getVerilogToken()==SEM_TOK)
   { prevType="";sigType="";}
  
  }
} // parsReg


// extracts function/task prototype 

void parseFunction(Entry* curF)
{
  QCString mod(getVerilogString());
  QCString type; 
 
 VhdlDocGen::deleteAllChars(mod,'\n');
 VhdlDocGen::deleteAllChars(mod,';');
  while(mod.stripPrefix(" "));
 
  int i=mod.findRev(']');
  if(i > 0){
    type=mod.left(i+1);
   	mod=mod.right(mod.length()-i-1);
  }
  else {
  QStringList ql=QStringList::split(" ",mod,false);
  if(ql.count()>1) {
    type=ql[0].data();
	mod=ql[1].data();
  }
  }
 
 VhdlDocGen::deleteAllChars(mod,' ');
 VhdlDocGen::deleteAllChars(type,' ');

  curF->name+=mod;
  if(type.stripPrefix("automatic"))
   curF->type+="automatic "+type; 
   else
  curF->type+=type;
}
							   

// extract (local)parameter declaration 

void parseParam(Entry* e)
{
   QCString prevType,qcs;
  QRegExp regg("[ \t]");

  if((CurrState==VerilogDocGen::STATE_FUNCTION || CurrState==VerilogDocGen::STATE_TASK  || generateItem)) return;
  
  QCString mod(getVerilogString());
  VhdlDocGen::deleteAllChars(mod,';');
  VhdlDocGen::deleteAllChars(mod,'\n');
  VhdlDocGen::deleteAllChars(mod,',');

  mod=mod.simplifyWhiteSpace();

 if(mod.at(mod.length()-1)==')') 
  mod.remove(mod.length()-1,1);

  mod.stripPrefix("#");
  while(mod.stripPrefix(" "));
  mod.stripPrefix("(");



if(mod.contains("="))
{
 int i=mod.find("=");
 qcs=mod.right(mod.length()-i-1);
 while(qcs.stripPrefix(" "));
 mod=mod.left(i);
}

 while(mod.stripPrefix(" "));

 int j=mod.find(regg,0);
			 if(j>0){
			 bool bb=false;
			 QCString sem=mod.mid(0,j);
			 if(sem=="integer"){ prevType=sem;bb=true;}
			 else if(sem=="real"){prevType=sem;bb=true;}
			 else if(sem=="realtime"){prevType=sem;bb=true;}
			 else if(sem=="time"){prevType=sem;bb=true;}
			 else if(sem=="signed"){prevType=sem;bb=true;}
			 else if(sem=="wire"){prevType=sem;bb=true;}
			 if(bb)
			 mod.stripPrefix(sem.data());
			 }

 
 while(mod.stripPrefix(" "));
  
  int i=mod.find(']');
  if(i > 0){
    prevType+=" ";
	prevType+=mod.left(i+1);
   	mod=mod.right(mod.length()-i-1);
  }
 

  VhdlDocGen::deleteAllChars(mod,' ');


// each local member must get its unique number, because in Verilog
// two local variables can have the same identifier.
// ( input Q, reg Q)
  mod.prepend(VhdlDocGen::getRecordNumber().data());
 
  Entry* pTemp=VerilogDocGen::makeNewEntry(mod.data(),Entry::VARIABLE_SEC,VerilogDocGen::PARAMETER,getVerilogPrevLine());
  //pTemp->fileName+=getVerilogParsingFile();
  pTemp->type=prevType;
  pTemp->args=qcs;
  
  
}

// extract  input/output ports

void parsePortDir(Entry* e,int port)
{

static QCString prevType;
static QCString type; 

QCString mod(getVerilogString());
 VhdlDocGen::deleteAllChars(mod,'\n');
 VhdlDocGen::deleteAllChars(mod,')');
 VhdlDocGen::deleteAllChars(mod,'(');
 VhdlDocGen::deleteAllChars(mod,';');
 VhdlDocGen::deleteAllChars(mod,',');

 while(mod.stripPrefix(" "));


if(mod.stripPrefix("input"))
 prevType="";
else if(mod.stripPrefix("output"))
  prevType=""; 
else if(mod.stripPrefix("inout"))
  prevType="";
else {
             QRegExp regg("[ \\[]");
  			 int j=mod.find(regg,0);
			 if(j>0){
			 type=mod.mid(0,j);
			 mod.stripPrefix(type.data());
			 }
	 } 


while(mod.stripPrefix(" "));
 
QRegExp regg("[ \t]");
 int j=mod.find(regg,0);
			 if(j>0){
			 bool bb=false;
			 QCString sem=mod.mid(0,j);
			 if(sem=="integer"){ prevType=sem;bb=true;}
			 else if(sem=="real"){prevType=sem;bb=true;}
			 else if(sem=="realtime"){prevType=sem;bb=true;}
			 else if(sem=="time"){prevType=sem;bb=true;}
			 else if(sem=="signed"){prevType=sem;bb=true;}
			 else if(sem=="wire"){prevType=sem;bb=true;}
			 if(bb)
			 mod.stripPrefix(sem.data());
			 }

while(mod.stripPrefix(" "));
  
  int i=mod.findRev(']');
  if(i > 0){
    prevType+=" ";
	prevType+=mod.left(i+1);
   	mod=mod.right(mod.length()-i-1);
  }
  else{ 
  int j=mod.find(regg,0);
   if(j>0){
    QCString sem=mod.mid(0,j);
	if(sem=="reg"){		
     mod=mod.right(mod.length()-j-1);
     prevType+=" reg";
     }
    }
   }
  
  VhdlDocGen::deleteAllChars(mod,' ');
  mod.prepend(VhdlDocGen::getRecordNumber().data());
  if(CurrState==VerilogDocGen::STATE_MODULE){  
  Entry* pTemp=VerilogDocGen::makeNewEntry(mod.data(),Entry::VARIABLE_SEC,0,c_lloc.first_line);
  pTemp->type=prevType;
  pTemp->args=type;
   assert(currVerilogType!=0);
  pTemp->spec=currVerilogType;
//   VerilogDocGen::addSubEntry(currentVerilog,pTemp);
  }
  else
  { 
   if(CurrState==VerilogDocGen::STATE_FUNCTION){
      Argument *arg=new Argument;
      
      switch(currVerilogType) {
      
      case VerilogDocGen::INPUT: arg->type="Input";break;
      case VerilogDocGen::INOUT:arg->type="Inout";break;         
      case VerilogDocGen::OUTPUT:arg->type="Output";break;         
      default:break;
      }                           
        arg->defval=prevType;                         
        arg->name=mod;//(QCString)ql[j];	
	  currentFunctionVerilog->argList->append(arg);
	  VerilogDocGen::adjustMemberName(mod); 
	  currentFunctionVerilog->args+=mod;//(QCString)ql[j]+",";
  } 
 }
 

  if(getVerilogToken()==SEM_TOK)//end of line
  {prevType="";type="";}
}

void parseAlways(bool bBody)
{

if(currVerilogType!=VerilogDocGen::ALWAYS || generateItem) return ;

QRegExp regg1("[\\s]");

QCString mod(getVerilogString());
QCString type; 
QStringList ql;
bool sem=false;

 VhdlDocGen::deleteAllChars(mod,'@');
 VhdlDocGen::deleteAllChars(mod,'\n');
 VhdlDocGen::deleteAllChars(mod,'(');
 VhdlDocGen::deleteAllChars(mod,')');
 VhdlDocGen::deleteAllChars(mod,';'); 

bool semi=mod.contains(",");

if(semi)
  ql=QStringList::split(",",mod,false);
 else
  ql=QStringList::split(regg1,mod,false);
 

 if(!parseCode) {
 QCString temp;
 currentFunctionVerilog=VerilogDocGen::makeNewEntry(VhdlDocGen::getProcessNumber().data(),Entry::FUNCTION_SEC,VerilogDocGen::ALWAYS);
  currentFunctionVerilog->stat=TRUE;
  currentFunctionVerilog->fileName=getVerilogParsingFile();
  if(!bBody)
  for(uint j=0;j<ql.count();j++) {
  QCString ll=ql[j].data();
  temp+=ll;
  if(ll=="or" || ll=="and" || ll=="xor")
  {

    continue; 
  }

	//  currentFunctionVerilog->args+=',';
	  Argument *arg=new Argument;
      arg->name=ll.simplifyWhiteSpace();	
	  currentFunctionVerilog->argList->append(arg);
       if(!semi)
      {
      arg->name=mod;
      currentFunctionVerilog->args=mod; 
       return;
      }
      currentFunctionVerilog->args+=ll; 

 }
 return;
}


}//parseAlways



 // sets the current parsing module (only for parsing inline_sources)             
 void VerilogDocGen::setCurrVerilogClass(QCString& cl){ currVerilogClass = cl;}
   
 //-------------------------------------------------------------------------------------------  
           
 int MyParserConv::parse(MyParserConv* conv){
  myconv=conv;
  assert(myconv);
  return c_parse();
 } 
        
int c_lex(void){
 return myconv->doLex(); 
}


void c_error(const char * err){
   if(err){// && !parseCode){
 //fprintf(stderr,"\n\nerror  at line [%d]... : in file [%s]\n\n",c_lloc.first_line,getVerilogParsingFile());
  vbufreset();
 // exit(0);
  }
  
   } 
    
int getVerilogToken(){return c_char;}
 //------------------------------------------------------------------------------------------------  

// writes a digit to the source

void writeDigit()
 {
   if(parseCode) {
     writePrevVerilogWords(identVerilog);
	 writeVerilogFont("vhdllogic",identVerilog.data());
	 printVerilogBuffer(true);
	 }
	identVerilog.resize(0);

 }// writeDigit

// prints and links the parsed identifiers  

void parseString(){				
					 				
					if(parseCode ) { 
					 //   printVerilogStringList();
						 identVerilog=identVerilog.stripWhiteSpace();
				   	  writePrevVerilogWords(identVerilog);
						 bool b=false;
					 
					 if(currVerilogType==VerilogDocGen::DEFPARAM){
				       QCString s(getVerilogString());
                       if(s.contains(".")==0)
                           b=generateVerilogMemLink(currVerilogClass,identVerilog,VerilogDocGen::COMPONENT);
				       else if(s.contains("="))
                           b=generateVerilogMemLink(currVerilogClass,identVerilog,-1);
                       else
				         b=generateVerilogMemLink(currVerilogInst,identVerilog,-1);	       
				     }
					 else if(currVerilogType==VerilogDocGen::COMPONENT){
					    QCString tt(getVerilogString());
					    
							
						if(tt.contains('(') || !tt.contains('.'))
					     b=generateVerilogCompMemLink(currVerilogClass,currVerilogInst,identVerilog,false);
				        else if(!b)   
				         b=generateVerilogCompMemLink(currVerilogClass ,currVerilogInst,identVerilog,true);
						
						if(!b){
							  codifyVerilogString(identVerilog.data(),"vhdlchar");
				         b=true;
						 }
						//if(!b)   
				        // b=generateVerilogCompMemLink(currVerilogClass,currVerilogInst,identVerilog,false);    
					   }
				  
				      else if(currVerilogType==VerilogDocGen::PORT)
                        b=generateVerilogMemLink(currVerilogClass,identVerilog,VerilogDocGen::PORT);
				     else if(currVerilogType==VerilogDocGen::PARAMETER)
                        b=generateVerilogMemLink(currVerilogClass,identVerilog,VerilogDocGen::PARAMETER);
				     else if(currVerilogType==VerilogDocGen::SIGNAL)
                        b=generateVerilogMemLink(currVerilogClass,identVerilog,VerilogDocGen::SIGNAL);
				     else if(currVerilogType==VerilogDocGen::INPUT)
                        b=generateVerilogMemLink(currVerilogClass,identVerilog,VerilogDocGen::INPUT);				       
         		     else if(currVerilogType==VerilogDocGen::OUTPUT)
                        b=generateVerilogMemLink(currVerilogClass,identVerilog,VerilogDocGen::OUTPUT);
				     else if(currVerilogType==VerilogDocGen::INOUT)
                        b=generateVerilogMemLink(currVerilogClass,identVerilog,VerilogDocGen::INOUT);
				   
				     else if(currVerilogType==VerilogDocGen::ALWAYS)
                        b=generateVerilogMemLink(currVerilogClass,identVerilog,VerilogDocGen::ALWAYS);
						
				     if(!b){
					   b =  generateVerilogMemLink(currVerilogClass,identVerilog,-1); 
					   if(!b && getClass(identVerilog.data()))
                       b=generateVerilogClassOrGlobalLink(identVerilog.data());
					  if(!b){
					  const QCString*  col=VerilogDocGen::findKeyWord(identVerilog.data());
					  if(col) 
					  codifyVerilogString(identVerilog.data(),col->data());
					  else					  
					  codifyVerilogString(identVerilog.data(),"vhdlchar");
					   }   
					 }
					   printVerilogBuffer(true);
					  }
				    prevName=identVerilog;
				    identVerilog.resize(0);
				 
}// parseString

// inits the parser

 //---------------------------------------------------------------------------------------------------  


// do not include the same class twice 

bool findExtendsComponent(QList<BaseInfo> *extend,QCString& compName)
{
 for(uint j=0;j<extend->count();j++){
  BaseInfo *bb=extend->at(j);
  if(bb->name==compName)
   return true;
 }
 return false;
}// findExtendsComponent

void resetVerilogBrief() {briefString.resize(0); }
