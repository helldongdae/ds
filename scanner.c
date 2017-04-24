#include <stdio.h>
#include "myscanner.h"


#define true 1;
#define false 0;
extern int yylex();
extern char* yytext;
extern FILE* yyin;
FILE* outFile;


void print_text(char* color, int font){
    if(font == FONT_normal){
        fprintf(outFile,"<p><font color=\"%s\">", color);
        fprintf(outFile,"%s", yytext);
        fprintf(outFile,"%s", "</font></p>");
    }
    else if(font == FONT_bold){
        fprintf(outFile,"<p><strong><font color=\"%s\">", color);
        fprintf(outFile,"%s", yytext);
        fprintf(outFile,"%s", "</font></strong></p>");
    }
}
int is_legal(){
    //if(문법맞으면){
    return true;
    //else if(문법틀리면){
    return false;
}
void CHECK_legal_AND_print(){
    if(is_legal())
        print_text(COLOR_normal, FONT_normal);
    else
        print_text(COLOR_illegal,FONT_bold);
}

//제출 전에 해결하고 주석 삭제하기, 코드만 잘 돌아간다고 제출말고 원리를 알고 보고서에 쓰자

//filename.l  lex파일 에서
//? []안에 들어가면 특수문자 따로 처리 안해도 되나? [] 안에서는 -를 제외한 연산이 가능한가?
//? [^ab] 이면 [^a]|[b] 인가 아니면 [(^a)(^b)] 인가?
//here <- [+|-] or ([+]|[-])
//here <- [^\"\n\"] or [^\n]
//here[^'] or[^\']
//id-var 인식에서 yyless(-1) 애매함 yyless(1)인거 같은데


int main(int argc, char** argv){
    //argv[0] is this program name
    //argv[1] is param filename : <f>.java
    //this program's output is  : <f>.html
    yyin=fopen(argv[1], "r");
    char* _tmp = strtok(argv[1], ".java");
    char* _outFileName = strcat(_tmp, ".html");
    outFile = fopen(_outFileName, "w");
    fprintf(outFile, "%s", "<HTML><body>");
    
    int ENUM_token =yylex();
    while( 0< ENUM_token){
        switch(ENUM_token){
            case TYPE_comment : print_text(COLOR_comment, FONT_normal); break;
            case TYPE_comment_newline : print_text(COLOR_comment, FONT_normal); fprintf(outFile,"%s", "<br/>"); break;
            case TYPE_int : print_text(COLOR_int, FONT_normal); break;
            case TYPE_float : print_text(COLOR_float, FONT_normal); break;
            case TYPE_bool : print_text(COLOR_bool, FONT_normal); break;
            case TYPE_str : print_text(COLOR_str, FONT_normal); break;
            case TYPE_char : print_text(COLOR_char, FONT_normal); break;
            case TYPE_null : print_text(COLOR_null, FONT_normal); break;
            case TYPE_general : print_text(COLOR_normal, FONT_normal); break;
                
            case TYPE_op : print_text(COLOR_op, FONT_normal); break;
            case TYPE_separator : print_text(COLOR_seperator, FONT_normal); break;
            case TYPE_charKeyBoard : print_text(COLOR_charKeyBoard, FONT_normal); break;
            case TYPE_id : print_text(COLOR_id, FONT_normal); break;
            case TYPE_method : print_text(COLOR_method, FONT_normal); break;
            case TYPE_space : print_text(COLOR_space, FONT_normal); break;
            case TYPE_newline : print_text(COLOR_newline, FONT_normal); break;
                
            default: CHECK_legal_AND_print();
        }
        ENUM_token =yylex();
    }
    fprintf(outFile, "%s", "</body></HTML>");
    
    fclose(outFile);
    fclose(yyin);
    return 0;
}
