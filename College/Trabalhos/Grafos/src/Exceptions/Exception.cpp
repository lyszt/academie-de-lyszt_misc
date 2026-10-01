#include "Exception.h"

Exception::Exception(const std::string &message)
    : std::runtime_error(message), cause_(nullptr) {
}

Exception::Exception(const std::string &message, std::exception_ptr cause)
    : std::runtime_error(message), cause_(cause) {
}

std::exception_ptr Exception::cause() const {
    return cause_;
}

void Exception::print(std::ostream &out) const {
    print(*this, out);
}

void Exception::print(const std::exception &e, std::ostream &out, int level) {
    out << "exception: " << std::string(level, ' ') << e.what() << "\n";

    const Exception *own = dynamic_cast<const Exception *>(&e);
    if (own == nullptr || own->cause_ == nullptr) {
        return;
    }

    try {
        std::rethrow_exception(own->cause_);
    } catch (const std::exception &cause) {
        print(cause, out, level + 2);
    } catch (...) {
        out << "exception: " << std::string(level + 2, ' ') << "(unknown)\n";
    }
}
