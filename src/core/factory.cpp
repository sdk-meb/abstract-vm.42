# include <factory.hpp>

IOperand const * Factory::createInt8(std::string const & value) const {
    return new Int8(value);
}

IOperand const * Factory::createInt16(std::string const & value) const {
    return new Int16(value);
}

IOperand const * Factory::createInt32(std::string const & value) const {
    return new Int32(value);
}

IOperand const * Factory::createFloat(std::string const & value) const {
    return new Float(value);
}

IOperand const * Factory::createDouble(std::string const & value) const {
    return new Double(value);
}

IOperand const * Factory::createOperand(eOperandType type, std::string const & value) const {

    static IOperand const * (Factory::*functions[])(std::string const &) const = {
        &Factory::createInt8,
        &Factory::createInt16,
        &Factory::createInt32,
        &Factory::createFloat,
        &Factory::createDouble
    };
    try {
        return (this->*functions[static_cast<int>(type)])(value);
    } catch (const std::exception& e) {
        throw InterpretationExept("Error: " + static_cast<std::string>( e.what()) + " -> Operands(" + eOperandstoString(type) + ")");
    }
}
