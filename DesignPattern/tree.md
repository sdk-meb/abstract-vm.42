# graphql

```shell
$ tree Abstract-vm/
    ├── Makefile                        # Build instructions
    ├── README.md                       # Project documentation
    ├── src/
    │   ├── main.cpp                    # Entry point of the program
    │   ├── core/*.cpp
    │   │   ├── factory                 # Implementation of OperandFactory
    │   │   ├── Instructions/
    │   │   │   ├── add                     # Implementation of add instruction
    │   │   │   ├── assert                  # Implementation of assert instruction
    │   │   │   ├── div                     # Implementation of div instruction
    │   │   │   ├── dump                    # Implementation of dump instruction
    │   │   │   ├── exit                    # Implementation of exit instruction
    │   │   │   ├── interface_instranctions # Interface for instructions
    │   │   │   ├── mod                     # Implementation of mod instruction
    │   │   │   ├── mul                     # Implementation of mul instruction
    │   │   │   ├── pop                     # Implementation of pop instruction
    │   │   │   ├── print                   # Implementation of print instruction
    │   │   │   ├── push                    # Implementation of push instruction
    │   │   │   └── sub                     # Implementation of sub instruction
    │   │   ├── Operands/
    │   │   │   ├── Double         # Implementation of DoubleOperand
    │   │   │   ├── Float          # Implementation of FloatOperand
    │   │   │   ├── Int16          # Implementation of Int16Operand
    │   │   │   ├── Int32          # Implementation of Int32Operand
    │   │   │   └── Int8           # Implementation of Int8Operand
    │   │   ├── Utils/
    │   │   │   ├── operand        # Operand utility functions
    │   │   │   └── parsser        # Parser utility functions
    │   │   ├── vm                 # Virtual Machine implementation
    │   │   └── vm_interpreter     # VM interpreter implementation
    │   │ 
    │   ├── Dignoses/
    │   │   ├── Core/*.cpp
    │   │   │   ├── diagnostics     # Diagnostics implementation
    │   │   │   └── logger          # Logger implementation
    │   │   └── Includes/*.hpp
    │   │       ├── diagnostics     # Diagnostics declarations
    │   │       └── logger          # Logger declarations
    │   │
    │   └── Includes/
    │       ├── factory.hpp             # Declaration of OperandFactory
    │       ├── Instructions/
    │       │   ├── add.hpp             # Declaration of add instruction
    │       │   ├── assert.hpp          # Declaration of assert instruction
    │       │   ├── div.hpp             # Declaration of div instruction
    │       │   ├── dump.hpp            # Declaration of dump instruction
    │       │   ├── exit.hpp            # Declaration of exit instruction
    │       │   ├── interface_instranctions.hpp # Interface for instructions
    │       │   ├── mod.hpp             # Declaration of mod instruction
    │       │   ├── mul.hpp             # Declaration of mul instruction
    │       │   ├── pop.hpp             # Declaration of pop instruction
    │       │   ├── print.hpp           # Declaration of print instruction
    │       │   ├── push.hpp            # Declaration of push instruction
    │       │   └── sub.hpp             # Declaration of sub instruction
    │       ├── Operands/
    │       │   ├── _IOperand.hpp       # Operand interface
    │       │   ├── operand_impl.tpp    # Operand implementation templates
    │       │   ├── operands.hpp        # Operand declarations
    │       │   └── operand.tpp         # Operand templates
    │       ├── Utils/
    │       │   ├── mode.hpp            # Mode utility functions
    │       │   └── parsser.hpp         # Parser utility functions
    │       └── vm.hpp                  # Declaration of the Virtual Machine class
    │
    ├── tests/*.asm                 # Unit tests
    │   ├── add                     # Test for add instruction
    │   ├── assert                  # Test for assert instruction
    │   ├── div                     # Test for div instruction
    │   ├── dump                    # Test for dump instruction
    │   ├── lexer                   # Test for lexer
    │   ├── mod                     # Test for mod instruction
    │   ├── mul                     # Test for mul instruction
    │   ├── pop                     # Test for pop instruction
    │   ├── print                   # Test for print instruction
    │   ├── push                    # Test for push instruction
    │   └── sub                     # Test for sub instruction
    │
    ├── public/                         # Public assets (e.g., images, fonts)
    │   ├── example_of_assembly_rogram.png # Example of assembly program
    │   └── W3sDesign_Factory_Method_Design_Pattern_UML.jpeg # UML diagram
    ├── build/
    │
    ├── scripts/                        # Helper scripts for building, running, and debugging
    │   └── global_test.sh              # Global test script
    └── DesignPattern/
*       ├── tree.md                     # Explanation of the project tree structure
        ├── UML/
        │   └── class_diagram.md        # UML diagrams for the project
        ├── grammar.md                  # Grammar rules (EBNF format)
        ├── lexser_parsse.md            # Lexer and parser explanation
        ├── notes.md                    # Additional pattern explanations
        └── operand_operations_summary_comparison.md # Operand operations summary
```