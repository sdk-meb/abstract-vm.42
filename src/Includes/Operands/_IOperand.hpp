#ifndef IOPERAND_HPP
#define IOPERAND_HPP

#include <string>
#include <unordered_map>

/**
 *  @include diagnostics
 */
#include <diagnostics.hpp>

enum class eOperandType {

    Int8,
    Int16,
    Int32,
    Float,
    Double 
};
const std::string& eOperandstoString(eOperandType type);


#define types_count 5

class IOperand {

    protected:
        eOperandType _type;
        std::string _stringValue;

    public:
        virtual int getPrecision( void ) const = 0; // Precision of the type of the instance
        virtual eOperandType getType( void ) const = 0; // Type of the instance
        virtual IOperand const * operator+( IOperand const & rhs ) const = 0; // Sum
        virtual IOperand const * operator-( IOperand const & rhs ) const = 0; // Difference
        virtual IOperand const * operator*( IOperand const & rhs ) const = 0; // Product
        virtual IOperand const * operator/( IOperand const & rhs ) const = 0; // Quotient
        virtual IOperand const * operator%( IOperand const & rhs ) const = 0; // Modulo
        virtual std::string const & toString( void ) const = 0; // String representation of the instance
        virtual ~IOperand( void ) {}
};

#endif

