#pragma once

#include <optional>
#include <string>

namespace options
{
    class Options
    {
    public:
        Options(int argc, char *argv[]);
        ~Options() = default;

        bool is_docker() const;
        const char *get_docker() const;
        const char *get_rootfs() const;
        std::optional<std::string> get_student_dir() const;
        char **get_moulette_prog();

    private:
        bool is_docker_ = false;
        char *student_dir_ = NULL;
        union
        {
            char *docker;
            char *rootfs;
        } path_;
        char **moulette_prog_;
    };
}
