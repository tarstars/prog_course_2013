#ifndef DEFINES_H_
#define DEFINES_H_

#include <string>
enum OperationType
{
    Operation_Plus     = 0,
    Operation_Subtract = 1,
    Operation_Multiply = 2,
    Operation_Divide   = 3
};

std::string kOperationStrings[] = {"sum (+)",
                                   "subtract (-)",
                                   "multiply (*)",
                                   "divide (/)"};

std::string kOperationDefines[] = {"OPERATION_PLUS",
                                   "OPERATION_SUBT",
                                   "OPERATION_MULT",
                                   "OPERATION_DIVD"};

#endif  //DEFINES_H_
