#if not defined(__OPERANDS_HPP)
#define __OPERANDS_HPP


#include <Operands/operand.tpp>
#include <limits>

#ifndef INT8_HPP 
#define INT8_HPP


class Int8 : public Operand<__int8_t> {

    public:
        explicit Int8(std::string const &);
};

#endif // INT8_HPP
#ifndef INT16_HPP
#define INT16_HPP


class Int16 : public Operand<__int16_t> {

    public:
        explicit Int16(std::string const &);
};


#endif // INT16_HPP
#ifndef INT32_HPP
#define INT32_HPP


class Int32 : public Operand<int32_t> {

    public:
        explicit Int32(std::string const &);
};


#endif // INT32_HPP
#ifndef FLOAT_HPP
#define FLOAT_HPP


class Float : public Operand<float> {

    public:
        explicit Float(std::string const &);
};


#endif // FLOAT_HPP
#ifndef DOUBLE_HPP
#define DOUBLE_HPP


class Double : public Operand<double> {

    public:
        explicit Double(std::string const &);
};


#endif // DOUBLE_HPP



#endif
