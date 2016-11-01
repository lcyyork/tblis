#ifndef _TBLIS_1T_SCALE_H_
#define _TBLIS_1T_SCALE_H_

#include "util/thread.h"
#include "util/basic_types.h"

#ifdef __cplusplus

namespace tblis
{

extern "C"
{

#endif

void tblis_tensor_scale(const tblis_comm* comm, const tblis_config* cfg,
                        tblis_tensor* A, const label_type* idx_A);

#ifdef __cplusplus

}

template <typename T>
void scale(tensor_view<T> A, const label_type* idx_A)
{
    tblis_tensor A_s(A);

    tblis_tensor_scale(nullptr, nullptr, &A_s, idx_A);
}

template <typename T>
void scale(single_t s, tensor_view<T> A, const label_type* idx_A)
{
    tblis_tensor A_s(A);

    tblis_tensor_scale(tblis_single, nullptr, &A_s, idx_A);
}

template <typename T>
void scale(const communicator& comm, tensor_view<T> A, const label_type* idx_A)
{
    tblis_tensor A_s(A);

    tblis_tensor_scale(comm, nullptr, &A_s, idx_A);
}

}

#endif

#endif
