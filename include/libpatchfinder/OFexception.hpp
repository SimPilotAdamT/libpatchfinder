#ifndef OFexception_hpp
#define OFexception_hpp

#include <libgeneral/macros.h>
#include <libgeneral/exception.hpp>

namespace tihmstar {
    class OFexception : public tihmstar::exception {
        //struct ExceptionData {
            //const char* commit_count_str;
            //const char* commit_sha_str;
            //int line;
            //const char* filename;
        //};
        //ExceptionData _exceptionData;
        public:
            // Inheriting constructors from the base class
            using exception::exception;
            explicit OFexception(const char* message) : exception(message) {}
            //OFexception(const char* commit_count_str, const char* commit_sha_str, int line, const char* filename)
              //  : _exceptionData{commit_count_str, commit_sha_str, line, filename}, exception(_exceptionData) {}
            //void initializeBaseClass() {
                //exception::commit_count_str = _commit_count_str;
                //exception::commit_sha_str = _commit_sha_str;
                //exception::line = _line;
                //exception::filename = _filename;
            //}
    };

    // Custom exceptions for making it easy to catch
    class out_of_range : public OFexception {
        using OFexception::OFexception;
    };

    class not_found : public OFexception {
        using OFexception::OFexception;
    };

    class symbol_not_found : public OFexception {
        using OFexception::OFexception;
    };

    class load_command_not_found : public OFexception {
        int _cmd;

    public:
        int cmd() const { return _cmd; };

        // Constructor for load_command_not_found
        load_command_not_found(const char* commit_count_str, const char* commit_sha_str, int line, const char* filename, int cmd)
            : OFexception(commit_count_str, commit_sha_str, line, filename), _cmd(cmd) {
            initializeBaseClass();
}

    };

    class symtab_not_found : public OFexception {
        using OFexception::OFexception;
    };

    class limit_reached : public OFexception {
        using OFexception::OFexception;
    };

    class bad_branch_destination : public OFexception {
        using OFexception::OFexception;
    };
}

#endif /* OFexception_hpp */
