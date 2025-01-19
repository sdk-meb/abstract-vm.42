#include "../../Includes/Operands/IOperand.hpp"

const std::string& eOperandstoString(eOperandType type) {

        static const std::unordered_map<eOperandType, std::string> operandtype = {
        {eOperandType::Int8, "Int8"},
        {eOperandType::Int16, "Int16"},
        {eOperandType::Int32, "Int32"},
        {eOperandType::Float, "Float"},
        {eOperandType::Double, "Double"},
    };

    return operandtype.find(type)->second;
}
