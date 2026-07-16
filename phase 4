// ============================================================
// PHASE 4: SHADER (HLSL INLINE)
// Purpose: Define ray generation, miss, hit
// ============================================================

const char* shaderCode = R"(
struct RayPayload { float4 color; };

[shader("raygeneration")]
void RayGen()
{
    RayPayload payload;
    payload.color = float4(1,0,0,1);
}

[shader("miss")]
void Miss(inout RayPayload payload)
{
    payload.color = float4(0,0,0,1);
}

[shader("closesthit")]
void ClosestHit(inout RayPayload payload)
{
    payload.color = float4(0,1,0,1);
}
)";
