// ============================================================
// PHASE 5: RAY DISPATCH
// Purpose: Execute ray tracing on GPU
// ============================================================

void DispatchRays()
{
    D3D12_DISPATCH_RAYS_DESC desc = {};
    desc.Width = 800;
    desc.Height = 600;
    desc.Depth = 1;

    commandList->DispatchRays(&desc);
}

// ============================================================
// MAIN ENTRY
// ============================================================

int main()
{
    try
    {
        InitDXRDevice();
        CreateCommandObjects();
        BuildBLAS();
        DispatchRays();

        std::cout << "DXR Initialized Successfully!" << std::endl;
    }
    catch (std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

// ============================================================
// END OF STEP 1 (BASICS)
// ============================================================
