// ============================================================
// STEP 1: BASICS
// ============================================================
// Goal: Build a minimal but REAL DXR pipeline (no shortcuts)
// ============================================================

// ============================================================
// PHASE 1: DEVICE + DXR INITIALIZATION
// Purpose: Create DX12 device with ray tracing support
// ============================================================

#include <windows.h>
#include <wrl.h>
#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3d12shader.h>
#include <DirectXMath.h>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace Microsoft::WRL;

ComPtr<ID3D12Device5> device;
ComPtr<IDXGIFactory6> factory;

void InitDXRDevice()
{
    CreateDXGIFactory1(IID_PPV_ARGS(&factory));

    ComPtr<IDXGIAdapter1> adapter;

    for (UINT i = 0; factory->EnumAdapters1(i, &adapter) != DXGI_ERROR_NOT_FOUND; ++i)
    {
        DXGI_ADAPTER_DESC1 desc;
        adapter->GetDesc1(&desc);

        if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE) continue;

        if (SUCCEEDED(D3D12CreateDevice(adapter.Get(), D3D_FEATURE_LEVEL_12_1, IID_PPV_ARGS(&device))))
        {
            break;
        }
    }

    if (!device)
        throw std::runtime_error("DXR Device creation failed");
}
