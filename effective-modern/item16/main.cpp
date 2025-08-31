#include <vector>
#include <mutex>
#include <atomic>

class Polynomial
{
public:
    using RootsType = std::vector<double>;

    RootsType roots() const
    {
        std::lock_guard<std::mutex> g{m};
        if (rootsAreValid == false)
        { // if cache not valid

            // compute roots,
            // store them in rootVals
            rootsAreValid = true;
        }
        count++;
        return rootVals;
    }

private:
    mutable bool rootsAreValid = false;
    mutable RootsType rootVals;
    mutable std::mutex m;
    mutable std::atomic<unsigned int> count{0};
};