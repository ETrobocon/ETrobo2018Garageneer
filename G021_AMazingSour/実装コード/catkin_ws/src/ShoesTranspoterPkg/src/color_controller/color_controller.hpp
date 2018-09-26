#include <stdio.h>
#include <stdlib.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <chrono>
#include <time.h>

/* �񋓌^�F���o����F */
enum EN_Color
{
	en_color_red,                         /* �ԐF(0) */
	en_color_green,                       /* �ΐF(1) */
	en_color_blue,                        /* �F(2) */
	en_color_yellow,                      /* ���F(3) */
	en_color_black,                       /* ���F(4) */
	en_color_error
};

/* �N���X�F�J���[�R���g���[���i�J���[�Z���T����N���X�j */
class ColorController
{
/* �A�g���r���[�g */
private:  //����J����
	int m_color_r;                        /* r�̒l */
	int m_color_g;                        /* g�̒l */
	int m_color_b;                        /* b�̒l */
	char *m_bus = "/dev/i2c-1";  /* i2c�̒ʐM�o�X�ւ̃p�X */
	int m_file;			/* �J���[�Z���T�̒ʐM�o�X */
	int m_flag = 0;			/* �J���[�Z���T�̏������t���O */

/* �R���X�g���N�^�ƃf�X�g���N�^ */
public: //���J����
	     ColorController(){};                    /* �R���X�g���N�^ */
    	~ColorController(){};                   /* �f�X�g���N�^ */

/* ���\�b�h */
public: //���J����
	EN_Color getColor();                  /* �F���擾 */
	EN_Color classifyColor();             /* �F�̎��� */
	void initColor();			/* �J���[�Z���T�������֐� */
};

#define COLOR_THRESHOLD_F 0.5    /* �������ő�ƂȂ�rgb�������邽�߂�臒l */
#define COLOR_THRESHOLD_S 0.3     /* ������2�Ԗڂɑ傫��rgb�������邽�߂�臒l*/
#define COLOR_THRESHOLD 20000    /* ���F���o�̂��߂�臒l */