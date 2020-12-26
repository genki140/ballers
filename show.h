#ifndef SHOW_HED
#define SHOW_HED



#include <dshow.h>

IGraphBuilder *pGraph = NULL;
IMediaControl *pMediaControl = NULL;
IMediaSeeking *pMediaSeeking = NULL;
IMediaEvent   *pEvent = NULL;








bool ShowSetting(int num)
{

	// クリーン アップ。
	if(pMediaControl!=NULL){pMediaControl->Release();pMediaControl=NULL;}
	if(pMediaSeeking!=NULL){pMediaSeeking->Release();pMediaSeeking=NULL;}	
	if(pEvent!=NULL){pEvent->Release();pEvent=NULL;}
	if(pGraph!=NULL){pGraph->Release();pGraph=NULL;}
	CoUninitialize();

	CoInitialize(NULL);
	
	// フィルタグラフマネージャを作成し、インターフェイスをクエリする。
	CoCreateInstance(CLSID_FilterGraph, NULL, CLSCTX_INPROC_SERVER,
						IID_IGraphBuilder, (void **)&pGraph);
	pGraph->QueryInterface(IID_IMediaControl, (void **)&pMediaControl);
	pGraph->QueryInterface(IID_IMediaSeeking, (void **)&pMediaSeeking);
	pGraph->QueryInterface(IID_IMediaEvent, (void **)&pEvent);


	if(Setting.BGM)
	{

		if(num==0)
			pGraph->RenderFile(L"data/music/opning", NULL);
		else if(num==1)
			pGraph->RenderFile(L"data/music/ending", NULL);
		else if(num==2)
			pGraph->RenderFile(L"data/music/stage", NULL);
		else if(num==3)
			pGraph->RenderFile(L"data/music/stage2", NULL);
		else if(num==4)
			pGraph->RenderFile(L"data/music/stage3", NULL);
		else if(num==5)
			pGraph->RenderFile(L"data/music/stage4", NULL);
		else if(num==6)
			pGraph->RenderFile(L"data/music/race", NULL);
		else if(num==7)
			pGraph->RenderFile(L"data/music/race2", NULL);
		else if(num==8)
			pGraph->RenderFile(L"data/music/race3", NULL);
	}

	//巻きもどし
	LONGLONG llPos = 0;
	pMediaSeeking->SetPositions(	&llPos, AM_SEEKING_AbsolutePositioning,
										&llPos, AM_SEEKING_NoPositioning);

	return true;

}



void ShowRelease()
{
    // クリーン アップ。
	if(pMediaControl!=NULL)
	{
	    pMediaControl->Release();
		pMediaControl=NULL;
	}
	if(pMediaSeeking!=NULL)
	{
	    pMediaSeeking->Release();
		pMediaSeeking=NULL;
	}
	if(pEvent!=NULL)
	{
	    pEvent->Release();
		pEvent=NULL;
	}
	if(pGraph!=NULL)
	{
	    pGraph->Release();
		pGraph=NULL;
	}

	CoUninitialize();

}




#endif
