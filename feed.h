#ifndef FEED_HED
#define FEED_HED


#include <d3dx8.h>



//�t�F�[�h�C���A�t�F�[�h�A�E�g�����邽�߂̃v���O����

enum { FEEDMODE_BLACKIN,FEEDMODE_BLACKOUT,FEEDMODE_WHITEIN,FEEDMODE_WHITEOUT};
//OUT�͂��񂾂񍕁i���j���Ȃ��čs��



class FeedClass
{
public:

	void Reset();
	void Move();
	void Start(int feedmode,int feedcount);
	void End();
	//color�͈̔͂�-1�`1�ŁA�}�C�i�X�Ȃ獕���A�v���X�Ȃ甒���Ȃ�悤�Ƀ����_�����O����
	//color��0�̎��́AFeedStart�Ŏw�肵���Ƃ���Ƀt�F�[�h����
	void Render(LPDIRECT3DDEVICE8 device,int width,int height);//,float color=0);

	bool GetEnable();//�t�F�[�h�����̃`�F�b�N



	int mode,count,countend;//mode��FEEDMODE_���i�[�Acount�͌��݂̃J�E���g���i�[���Acountend�̓J�E���g�I���ʒu���i�[

private:


	//�����̔p
	typedef struct{
		float   x, y, z, w;
		DWORD   color;
	} LVERTEX;

	//bool autoend;

};

#endif