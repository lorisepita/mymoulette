#pragma once

#include <archive.h>
#include <archive_entry.h>

#include <string>

namespace isolate
{
    class Tar
    {
        public:
            Tar(const std::string& dest);
            ~Tar();
            void untar(const std::string& data);

        private:
            const std::string dest_;
            struct archive *a_ = NULL;
            struct archive *ext_ = NULL;
    };

    class TarException : public std::exception
    {
        public:
            TarException(const std::string& msg);
            TarException(const std::string& msg, const char *tar_error);

            const char* what();

        private:
            std::string msg_;

    };

}
