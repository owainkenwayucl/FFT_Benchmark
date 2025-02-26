//
// Created by marcuskeil on 31/01/25.
//

#ifndef FFT_BENCH_ROCFFT_CLASS_HPP
#define FFT_BENCH_ROCFFT_CLASS_HPP
#include "rocfft/rocfft.h"
#include "Data_Functions.hpp"
#include "Abstract_FFT.hpp"

#if __has_include( "hip/hip_runtime_api.h" )
#include "hip/hip_runtime_api.h"
#else
#include <cuda_runtime.h>
#endif

#if __has_include( "matplotlibcpp.h" )
#include "matplotlibcpp.h"
namespace plt = matplotlibcpp;
#endif

class rocFFT_Class : Abstract_FFT{
private:
    std::complex<double> *source_data{};
    int vector_side;
    int vector_element_count;
    size_t vector_memory_size;

    rocfft_plan p = nullptr;
public:
    explicit rocFFT_Class(float memory_size); // memory_size given in MB
    ~rocFFT_Class();

    [[maybe_unused]] inline std::string name() override { return "rocFFT"; };
    [[maybe_unused]] [[nodiscard]] inline int get_side() const { return vector_side; };
    [[maybe_unused]] [[nodiscard]] inline size_t get_memory() const { return vector_memory_size; };
    [[maybe_unused]] [[nodiscard]] inline std::complex<double>* get_source() { return source_data; };
    [[maybe_unused]] [[nodiscard]] inline int get_element_count() const { return vector_element_count; };

    [[maybe_unused]] void transform() override;
    [[maybe_unused]] std::chrono::duration<double, std::milli> time_transform(int runs) override;

#if __has_include( "matplotlibcpp.h" )
    [[maybe_unused]] void create_preplot(const std::string& name);
    [[maybe_unused]] void create_postplot(const std::string& name);
#endif

};
#endif //FFT_BENCH_ROCFFT_CLASS_HPP
