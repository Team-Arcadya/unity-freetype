#include "interface.h"

FontContext* UFT_CreateFontContextByFile(const char* pPath)
{
    return new FontContext(pPath);
}

FontContext* UFT_CreateFontContextByData(const FT_Byte* pData, unsigned int length)
{
    return new FontContext(pData, length);
}

void UFT_DeleteFontContext(FontContext* pContext)
{
    if (pContext != nullptr)
    {
        delete pContext;
    }
}

const FT_Byte* UFT_GetGlyph(FontContext* pContext, int code, FreeTypeGlyph* glyph, int fontSize, int outlineSize, bool bold)
{
    const FT_Byte* pResult = nullptr;

    if (pContext != nullptr && glyph != nullptr)
    {
        pResult = pContext->GetGlyph(code, *glyph, fontSize, outlineSize, bold);
    }

    return pResult;
}

void UFT_MemoryCopy(unsigned int* pDst, unsigned int* pSrc, int size)
{
    memcpy(pDst, pSrc, size);
}


const FT_Size_Metrics* UFT_GetGlobalMetrics(FontContext* pContext,int size){
    const FT_Size_Metrics* pRet = nullptr;
    if(pContext!= nullptr && size > 0){
        FT_Size_Metrics ret;
        pContext->GetSizeMetrics(size,&ret);
        memcpy((void*)pRet,&ret,sizeof(FT_Size_Metrics));
    }
    return pRet;
}