#include <fstream>
#include <string>
#include <vector>
//#include "passDriver.h"
#include "ExprTestLexer.h"
#include "ExprTestParser.h"

#include "antlr4-runtime.h"

#include "MyCVisitor.cpp"

using namespace antlr_test;
using namespace std;
using namespace antlr4;
int main(int argc , char* argv[]) {
    vector<int> passSwitch;
    if (argc == 2){
        string arg(argv[1]);
        for(auto s: arg) {
            passSwitch.push_back(int(s - '0'));
        }
    }

    std::ifstream in;
    in.open("../test.sysy");
    ANTLRInputStream input(in);
    std::cout<<"input successfully!\n";
    //词法分析lexer
    ExprTestLexer lexer(&input);
    CommonTokenStream tokens(&lexer); //将输入的字符串分解为标记（tokens）,如关键字，操作符，数字等
    tokens.fill(); //将tokens存储起来，方便后续操作
    std::cout << "Tokens:" << std::endl;
    for (auto token : tokens.getTokens()) {
        std::cout << "Token Text: " << token->getText() 
                  << ", Type: " << token->getType()
                  << ", Line: " << token->getLine()
                  << ", Column: " << token->getCharPositionInLine() << std::endl;
    }
    std::cout<<"tokens successfully!\n";
    //语法分析器
    ExprTestParser parser(&tokens);
    std::cout<<"parser successfully!\n";
    //解析具体语法规则
    ExprTestParser::CalContext *root = parser.cal();
    //遍历语法树
    ASTVisitor visitor;
    int result=std::any_cast<int>(visitor.visit(root));
    std::cout<<"result:"<<result;
    //auto Builder = visitor.getBuilder();
    //PassDriver driver(std::move(M), std::move(Builder), passSwitch);
    //driver.run();
    //111    //111qq11111ff111

    return 0;
}