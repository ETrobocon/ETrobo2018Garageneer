#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "human_detector.hpp"

/******************************************************************************
 * �֐��� | int detectHuman(int *trans_id);                                   *
 * �T�v   | �l���F�؊֐�                                                      *
 * ����   | �ޏ�҂̌C������Ă���^���Ԃ�ID                                  *
 * �߂�l | ����҂��ޏ�҂�\�������^                                        *
 * �ڍ�   | �l���̎w��𔻕ʂ��A���ޏ�҂̔���i�������ȒP�Ȃ���python���g�p�j*
 ******************************************************************************/
int HumanDetector::detectHuman(int *trans_id){

	//�V�X�e���R�[����python�̃R�[�h�����s
	system("python ~/HumanDetector.py");

	//�ϐ��錾
	FILE *fp; //python�R�[�h�̃t�@�C���|�C���^
	int data[2]; // �o�͕ϐ��i0:���ޓX�Ҕ��ʐ����^�A1�F�ޓX�҂̏���Ă���^����ID�j

	fp = fopen("list.txt","r"); //python�ŕۑ������t�@�C�����I�[�v��

	// �t�@�C���I�[�v���G���[
	if(fp == NULL){
		printf("There is no data! \n");
		return -1;
	}

	// �t�@�C���̒l�ǂݍ��݁i�w����j
	for(int i=0;i<2;i++){
		fscanf(fp, "%d", &(data[i]) );
	}
	fclose(fp);

	// �F�؎ҁ������
	if(data[0] == 0){
		printf("[setmode = %d][id = %d]\n", data[0],data[1]);
		*trans_id = data[1];
		return 0;
	}
	// �F�؎ҁ��ޏ��
	else if(data[0] == 1){
		printf("[setmode = %d] [id = %d]\n", data[0],data[1]);
		*trans_id = data[1];
		return 1;
	}
	// �G���[
	else printf("[Error] Human_Detector \n");
}
