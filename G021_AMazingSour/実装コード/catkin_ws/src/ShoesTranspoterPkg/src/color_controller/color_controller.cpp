#include "color_controller.hpp"

/******************************************************************************
 * �֐��� | EN_Color getColor()                                               *
 * �T�v   | �F���擾�֐�                                                    *
 * ����   | �Ȃ�                                                              *
 * �߂�l | �F                                                                *
 * �ڍ�   | �w�肵���F�����o����B                                            *
 ******************************************************************************/
EN_Color ColorController::getColor()
{
	// �J���[�Z���T�̏�����
	initColor();

	// �f�[�^�擾����
	// Read 8 bytes of data from register(0x94)
	// register(0x94) = cData lsb, cData msb, red lsb, red msb, green lsb, green msb, blue lsb, blue msb
	// ����g�p����̂�RGB�݂̂̂��ߏ��8bit�Ɖ���8bit���g�p
	char reg[1] = { 0x94 }; // �ǂݍ��ރ��W�X�^�i0x94�j
	write(m_file, reg, 1); //m_file�Ƀ��W�X�^�̒l����������
	char data[8] = { 0 }; // register(0x94)�̒l�i�[�p�ϐ��A0�ŏ�����
	
	// m_file�ɏ������񂾒l��ϐ�data�Ɋi�[
	if (read(m_file, data, 8) != 8)
	{
		// �l�̓ǂݍ��ݎ��s
		printf("Erorr : Input/output Erorr \n");
	}
	else
	{
		// Convert the data
		m_color_r = (data[3] * 256 + data[2]);       /* �Ԃ̒l�i�ő�l�F65535�j*/
		m_color_g = (data[5] * 256 + data[4]);      /* �΂̒l�i�ő�l�F65535�j*/
		m_color_b = (data[7] * 256 + data[6]);      /* �̒l�i�ő�l�F65535�j*/
	}
	// �F�𔻕ʂ��āA�F�̎�ނ�Ԃ�
	return classifyColor();
}

/******************************************************************************
 * �֐��� | EN_Color classifyColor();                                         *
 * �T�v   | �F���ʊ֐�                                                        *
 * ����   | �Ȃ�                                                              *
 * �߂�l | �F                                                                *
 * �ڍ�   | �ǂ̐F���𔻒肷��֐�                                            *
 ******************************************************************************/
EN_Color ColorController::classifyColor()
{
	int i = 10;		// �o�͕ϐ��A�����l�͊O��l���i�[�B
	float temp_sum = m_color_r + m_color_g + m_color_b;		// ���K���p��rgb���a
	float temp_color_rate[3];	// rgb�̑��a�ɑ΂��銄���i���K������rgb�l�j

	// rgb�̐��K��
	temp_color_rate[0] = ((float)m_color_r)/temp_sum;
	temp_color_rate[1] = ((float)m_color_g)/temp_sum;
	temp_color_rate[2] = ((float)m_color_b)/temp_sum;

	// �F���ʏ���
	// �ԐF����
	if(temp_color_rate[0] >= COLOR_THRESHOLD_F)
	{
		i = en_color_red;
	}
	// �ΐF����
	if(temp_color_rate[1] >= COLOR_THRESHOLD_F)
	{
		i = en_color_green;
	}
	// �F����
	if(temp_color_rate[2] >= (COLOR_THRESHOLD_F)-0.1) // b��rg�ɔ�ׂĒl�����������߁A�I�t�Z�b�g
	{
		i = en_color_blue;
	}
	
	// ���F�^���F�i���F�j����
	// ���F��r��g�������Ȃ�
	if(temp_color_rate[0] >= COLOR_THRESHOLD_S && temp_color_rate[1] >= COLOR_THRESHOLD_S)
	{
		// ���F��b���Ⴍ�Ȃ邪�A�����݂̂Ŕ��ʂ���Ɣ��⍕�ł�b�������ٗl�ɒႢ��Ԃ�����̂�r�̒l�Ŕ���
		if(temp_color_rate[2] < COLOR_THRESHOLD_S && m_color_r >= COLOR_THRESHOLD)
		{
			i = en_color_yellow;
		}
		else
		{
			i = en_color_black;
		}
	}
	if (i == 10) /* �����l�̂܂܂Ȃ獕�F���� */
	{
		i = en_color_black;
	}

	/* ���ʊ��� */
	// ���ʂ����F��Ԃ�
	switch(i){
		case en_color_red:
			return en_color_red;
			break;
		case en_color_green:
			return en_color_green;
			break;
		case en_color_blue:
			return en_color_blue;
			break;
		case en_color_yellow:
			return en_color_yellow;
			break;
		case en_color_black:
			return en_color_black;
			break;
		default:
			printf("Invalid Color\n"); // �G���[
			return en_color_error;
	}
}

/******************************************************************************
 * �֐��� | void initColor();                                                 *
 * �T�v   | �J���[�Z���T�������֐�                                            *
 * ����   | �Ȃ�                                                              *
 * �߂�l | �Ȃ�                                                              *
 * �ڍ�   | �J���[�Z���T�̃o�X���擾���A�ǂݍ��ݏ������s��                    *
 ******************************************************************************/
void ColorController::initColor()
{
	// �J���[�Z���T�̏������͍ŏ��ɐF���擾����1�x�̂ݎ��s
	if(m_flag == 0)
	{
		m_flag++; // �t���O���]
		m_file = open(m_bus, O_RDWR); // �ʐM�o�X�̎擾
		
		// �o�X���擾�ł���������
        if (m_file < 0)
        {
                printf("Failed to open the bus. \n");
                exit(1);
        }
		
        // Get I2C device, TCS34725 I2C address is 0x29(41)
        ioctl(m_file, I2C_SLAVE, 0x29);

        // Select enable register(0x80)
        // Power ON, RGBC enable, wait time disable(0x03)
        char config[2] = { 0 };
        config[0] = 0x80;
        config[1] = 0x03;
        write(m_file, config, 2);
        
		// Select ALS time register(0x81)
        // Atime = 700 ms(0x00)
        config[0] = 0x81;
        config[1] = 0x00;
        write(m_file, config, 2);
        
		// Select Wait Time register(0x83)
        // WTIME : 2.4ms(0xFF)
        config[0] = 0x83;
        config[1] = 0xFF;
        write(m_file, config, 2);
        
		// Select control register(0x8F)
        // AGAIN = 1x(0x00)
        config[0] = 0x8F;
        config[1] = 0x00;
        write(m_file, config, 2);
		
        sleep(1); // �ݒ芮����1s���xwait���K�v
	}
}
