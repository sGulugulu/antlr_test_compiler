#include "ExprTestVisitor.h"
#include <iostream>
namespace antlr_test{
    class ASTVisitor :public ExprTestVisitor{
    public:
    virtual antlrcpp::Any visitCal(ExprTestParser::CalContext *context) {
        
        //std::cout<<context->getText()<<"\n";
        return visitChildren(context);
    };

    virtual antlrcpp::Any visitAdd(ExprTestParser::AddContext *context) {
        int left=std::any_cast<int>(visit(context->expr(0)));
        int right=std::any_cast<int>(visit(context->expr(1)));
        std::cout<<"加法！\n";
        return left+right;
    };

    virtual antlrcpp::Any visitMul(ExprTestParser::MulContext *context) {
        int left=std::any_cast<int>(visit(context->expr(0)));
        int right=std::any_cast<int>(visit(context->expr(1)));
        std::cout<<"乘法！\n";
        return left*right;
    };

    virtual antlrcpp::Any visitInt(ExprTestParser::IntContext *context) {
        std::cout<<std::stoi(context->getText());
        return std::stoi(context->getText());
    };
    


};
}
