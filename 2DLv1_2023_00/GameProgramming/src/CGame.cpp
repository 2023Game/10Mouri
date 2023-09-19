#include "CGame.h"
#include "CApplication.h"
#include "CBlock.h"
#include "CPoint.h"

CGame::CGame()
	:mpUi(nullptr)
	,mTime(0)
{
	mpUi = new CUi(); //UI�N���X�̃C���X�^���X�̐���
	//�e�N�X�`���̓���
	CApplication::Texture()->Load(TEXTURE);

	//�萔�̒�`
	const int ROWS = 15; //�s��
	const int COLS = 20; //��
	//2�����z��̃}�b�v
	int map[ROWS][COLS] =
	{
	 {1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0},
	 {0,0,0,0,2,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1},
	 {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
	 {0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0},
	 {0,0,0,0,0,0,4,0,0,3,0,0,4,0,1,0,0,0,0,0},
	 {1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0},
	 {0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1},
	 {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
	 {0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0},
	 {0,0,0,0,0,0,4,0,0,3,0,0,4,0,1,0,0,0,0,0},
	 {1,0,0,1,1,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0},
	 {0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,0,0,1,1},
	 {0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0},
	 {0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,0},
	 {0,0,0,0,0,0,4,0,0,3,0,0,4,0,1,0,0,0,0,0},
	};

	//�}�b�v�̍쐬
	//�s�����J��Ԃ�
	for (int row = 0; row < ROWS; row++)
	{
		    //�񐔕��J��Ԃ�
		for (int col = 0; col < COLS; col++)
		{
			    //1�̎�,�u���b�N����
			if (map[row][col] == 1)
			{
				  //�u���b�N�𐶐�����,�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CBlock(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE,
						CApplication::Texture()));
			}
			      //2�̎�,�v���C���[����
			if (map[row][col] == 2)
			{
				  //�v���C���[�𐶐�����,�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CPlayer2(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE,
						CApplication::Texture()));
			}
			      //3�̎�,�G����
			if (map[row][col] == 3)
			{
				  //�G�𐶐�����,�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CEnemy2(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE,
						CApplication::Texture()));
			}
			      //4�̎�,�܂�Ԃ��|�C���g�쐬
			if (map[row][col] == 4)
			{
				  //�܂�Ԃ��|�C���g�𐶐�����,�L�����N�^�}�l�[�W���ɒǉ�
				CApplication::CharacterManager()->Add(
					new CPoint(TIPSIZE + TIPSIZE * 2 * col,
						TIPSIZE + TIPSIZE * 2 * row,
						TIPSIZE, TIPSIZE,
						CCharacter::ETag::ETURN));
			}
		}
	}
}

void CGame::Update()
{
	  //�X�V,�Փ�,�폜,�G��
	CApplication::CharacterManager()->Update();
	CApplication::CharacterManager()->Collision();
	CApplication::CharacterManager()->Delete();
	CApplication::CharacterManager()->Render();
	//UI
	mpUi->Time(mTime++);
	mpUi->Hp(1);
	mpUi->Hp(CPlayer2::Hp());
	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
}

void CGame::Start()
{
	  //�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	  //UI����
	mpUi->Hp(CPlayer2::Hp());
	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Start();
}

bool CGame::IsOver()
{     //HP��0�ȉ������茋�ʂ�߂�
	return CPlayer2::Hp() <= 0;
}

void CGame::Over()
{
	  //�Q�[���̕`��
	CApplication::CharacterManager()->Render();
	  //UI����
	mpUi->Hp(CPlayer2::Hp());
	mpUi->Enemy(CEnemy2::Num());
	mpUi->Render();
	mpUi->Over();
}