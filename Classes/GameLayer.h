#pragma once
#include "cocos2d.h"
#include "Rule.h"
#include "Player.h"
#include "Poker.h"

USING_NS_CC;

class GameLayer : public CCLayer
{
public:

	GameLayer(void);
	~GameLayer(void);
	virtual bool init();
	CREATE_FUNC(GameLayer);

	bool initBackGround();
	bool createPokers();
	Poker *selectPoker(int pokerType,int num);
	bool initPlayer();
	bool initButton();
	void ShowScore(CCPoint pt,int score);//��ʾ���� �����������
	void menuCallBackOneScore(CCObject* sender);
	void menuCallBackTwoScore(CCObject* sender);
	void menuCallBackThreeScore(CCObject* sender);
	void menuCallDiZhu(CCObject* sender);//���е���
	void menuNotHandle(CCObject* sender);//����
	void menuHandle(CCObject* sender);//����
	void menuSuccess(CCObject* sender);//ʤ��
	void reStart();//���¿�ʼ
	bool IsOutPkFinish();//�Ƿ������
	void sendPk();//����
	void MovePk(Player* play,Poker* pk);//������Ч
	void func(CCNode* pSender, void* pData);
	void update(float delta);
	void playerPkCanClick();
private: 
	 CCArray* m_arrPokers;//���Ե���
	 CC_SYNTHESIZE(CCArray*,m_arrayPlayerOut,ArrayPlayerOut);//���Ҫ������
	 CC_SYNTHESIZE(Player*,m_playerOut,PlayerOut);//��ҳ�����
	 CC_SYNTHESIZE(Player*,m_player,Player);//���
	 Player* m_npcOne;//����1
	 Player* m_npcTwo;//����2
	 Player* m_Three;//��ʾ����ʣ����
	 Player* m_npcOneOut;//����1������
	 Player* m_npcTwoOut;//����2������

	 Rule rule;//�ƹ���
	 bool m_isCall[3];//��������
	 int m_callTime;//�����е���
	 Dictionary* strings;//��ȡ����
	 int m_outPk;//��ĳ�˳���
	 CCArray* m_arrFollowPk;//Ҫ������

	 Menu* m_menu;//�е����˵�
	 Menu* m_handle_menu;//���Ʋ˵�
	 Menu* m_success_menu;//�ɹ��˵�
	 Menu* m_lost_menu;//���˲˵�

	 CCLabelTTF* m_lableDiZhu;
	 int m_state;
	 int m_sendPk_num;
};