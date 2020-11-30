#include <vector>
#include <ostream>  // see note below
template<class Container>
std::ostream& write_container(const Container& c,
                     std::ostream& out,
                     char delimiter = '\n')
{
    bool write_sep = false;
    for (const auto& e: c) {
        if (write_sep)
            out << delimiter;
        else
            write_sep = true;
        out << e;
    }
    return out;
}
