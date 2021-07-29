//�˹ٸ� �ϱ� ���� �ܿ����ϴ� �޴� ���� ������
#include <iostream>
#include <random>
#define MAX_MENU_NUM 75
#define MAX_DAY_NUM 3
using namespace std;
bool isDayPractice(int select);
bool isQuit(int select);
void doDayPractice(int day, string* menu, string* answer, int* start, int* end);
int main(void) {
	string menu[MAX_MENU_NUM] = 
	{	//1����
		"��������������", "����������", "Ŀ�� �ٳ��� ������", "Ŀ�� ������", "�� ũ����", "���� �� ũ����", "�ٳ��� �� ũ����", 
		"��Ʈ�κ��� ġ��Ȧ��", "��Ű������", "��Ʈ������", "�÷��� ���Ʈ ������", "���� ���Ʈ ������", "���� ���Ʈ ������", 
		"���� ������", "�ڸ� ������", "û���� ������", "û���� ���̵�", "���� ���̵�", "���� ���� ���̵�", "�ڸ� ���̵�", "ü����", "���ӿ��̵�", "�ް����̵�", 
		//2����
		"���̽� ��Ʈũ�� ����", "���̽� ���������� ��", "���̽� ������� ��", "���̽� ����Ƽ��̼� ��", 
		"���̽� ������", "���̽� ���ڶ�", "���̽� �ް�����", "���̽� ��������", "���̽� ���", "���̽� ���ǳӶ�", "���̽� �ξ� ��ũƼ", 
		"���̽� ������", "���̽� ������", "���̽� ���� ������", "���̽� �ڸ���", "���̽� ��׷��� ĳ���� ���۹�Ʈ��", "��� ������", "��� �ڸ� ����Ƽ", 
		"���� ��Ű ������", "���� ������", "��ġ ���� ������", "�����ֽ�", "��� ���� ������", "���ڳ� Ŀ�� ������", 
		"���� �ٳ��� �ֽ�", "���� �ֽ�", "�����ֽ�", "�ʹ� �ֽ�",
		"��� ���� ��", "��� ���� ��ũƼ ��", "��� ���� ���� ��", "��� ��", "��� ��ũƼ ��", 
		//3����
		"���̽� �Ƹ޸�ī��", "���̽� ī���", "���̽� �ܾƸ޸�ī��", "���̽� ������� �Ƹ޸�ī��", "���̽� �ٴҶ� �Ƹ޸�ī��", "���̽� �ٴҶ� ��", 
		"���̽� ť�� ��", "���̽� Ƽ��̼� ��", "���̽� īǪġ��", "���̽� ļ��� �����ƶ�", "���̽� ī���ī", "���̽� ļ��� ī���ī", "���̽� ��Ʈ ī���ī", 
		"�ݵ��� Ŀ�� HOT", "�ݵ��� �� HOT", "�ݵ��� ���� (���ν����) HOT", "�ݵ��� Ŀ�� ICE", "�ݵ��� �� ICE", "�ݵ��� ���� (���ν����) ICE"
	};
	string answer[MAX_MENU_NUM] = 
	{   //1����
		"< �������������� >\n\n1. ������->��Ű���̽� 100ml, ���ں��̽� 150ml->����Ĩ 1����->\n���� ���� -> 1������ �����ְ�\n2. 20oz�ſ� �ְ�->����ũ��\n->���ڵ帮��, ļ���帮��, ����ũ��ġ",
		"< ���������� >\n\n1. ������->��Ű���̽� 125ml, �������̽� 125ml ->\n���� ���� -> 1������ �����ְ�\n2. 20oz�ſ� �ְ�->����ũ��\n->�����Ŀ��",
		"< Ŀ�ǹٳ��������� >\n\n1. ������->��Ű���̽� 150ml, ������ 50ml->�ٳ��� �Ŀ�� 3���� ->\n���� ���� -> 1������ �����ְ�\n2. 20oz�ſ� �ְ�->����ũ��\n->�ٳ���Ĩ 2��, ����Ĩ 2��, ������ �������� ���� �� �����",
		"< Ŀ�� ������ >\n\n1. ������->��Ű���̽� 200ml, Ŀ�ǿ��� 50ml ->\n���� ���� -> 1������ �����ְ�\n2. 20oz�ſ� �ְ�->����ũ��\n->Ŀ�ǿ���, ļ���÷�",
		"< ��ũ���� >\n\n1. ������->��Ű���̽� 150ml, ���� 100ml->�Ҹ��� 1��, �����÷� 2���� ->\n���� ����->������ 1����ư\n2. 20oz��->�Ҹ��� �� ������->���빰 �ֱ� ->\n3. �Ѳ��ݰ�->��� �Ҹ��� ä���ֱ�",
		"< ������ũ���� >\n\n1. ������->��Ű���̽� 150ml, ���� 100ml->�Ҹ��� 1��, ����ǻ�� 1���� ->\n���� ����->������ 1����ư\n2. 20oz��->�Ҹ��� �� ������ ä���->���빰 �ֱ� ->\n3. �Ѳ��ݰ�->��� �Ҹ��� ä���ֱ�",
		"< �ٳ�����ũ���� >\n\n1. ������->��Ű���̽� 150ml, ���� 100ml->�Ҹ��� 1��, �ٳ��� �Ŀ�� 2����, �����÷� 2����->\n���� ����->������ 1����ư\n2. 20oz��->�Ҹ��� �� ������ ä���->���빰 �ֱ� ->\n3. �Ѳ��ݰ�->��� �Ҹ��� ä���ֱ�", 
		" < ��Ʈ�κ���ġ��Ȧ�� >\n\n1. ������->���� 150ml->���Ʈ 3����->������� 150ml, �����÷� 1���� ->\n���� ����->������ 1�� ��ư\n2. 20oz�ſ� �ְ�->����ũ��\n->ġ��ť�� 6��, ����ũ��ġ",
		"< ��Ű������ >\n\n1. ������->��Ű���̽� 250ml->��Ű���� 3����->���� �Ѱ��� ����\n->������ 1����ư\n2. 20oz��->��Ű���� 1����->���빰 �ֱ�->����ũ�� ->\n������ ���� x2�� �ݾ� ���� ����x4������ ���ڰ� �������->��Ű����",
		"< ��Ʈ������ >\n\n1. ������->��Ʈ���̽� 250ml->����Ĩ 1���� ->\n���� �� ��->������ 1����ư\n2. 20oz�ſ� �ְ� ->\n��Ʈ����->����ũ��ġ",
		"< �÷��� ���Ʈ ������ >\n\n1. ������->���� 200ml, ���Ʈ 6����->�����÷� 1���� ->\n���� ����->������ 1����ư\n2. 20oz�ſ� �ְ� ��",
		"< ���� ���Ʈ ������ >\n\n1. ������->���� 150ml, ���Ʈ 3����->���� ���� 150ml, �����÷� 1���� ->\n���� ����->������ 1����ư\n2. 20oz�ſ� �ְ� ��",
		"< ���� ���Ʈ ������ >\n\n1. ������->���� 150ml, ���Ʈ 3����->���� 10ea, ���� ǻ�� 1���� ->\n���� �� ��->������ 1�� ��ư\n2. 20oz�ſ� �ְ� ��",
		"< ���� ������ >\n\n1. 24oz��->��Ʈ�� 4��, ���ӽ����̽� 4��\n������ �÷� 4����, ���ӽ÷� 3����->�����ش�\n2. ���� ����->���̴� ����->�����ش�",
		"< �ڸ� ������ >\n\n1. 24oz��->��Ʈ�� 2��, ���� �����̽� 2��\n������ �÷� 1����, ���ӽ÷� 2����, �ڸ��÷�, �ڸ�ǻ�� ���� 1����->�����ش�\n2. ���� ����->���̴� ����->�����ش�\n3. �ڸ� �����̽� 1�� �÷��ش�",
		"< û���� ������ >\n\n1. 24oz��->��Ʈ�� 2��, ���� �����̽� 2��,\n������ �÷� 1����, ���ӽ÷� 2����, û����ǻ�� 1����->�����ش�\n2. ���� ����->���̴� ����->�����ش�",
		"< û���� ���̵� >\n\n1. 24oz��->û���� ǻ�� 2����->���ӽ÷�1����\n2. ���� ����->���̴� ����->�����ش�",
		"< �����̵� >\n\n1. 24oz��->����ǻ�� 1.5���� + �����÷� 1���� ->\n���� ����->���̴�->�����ش�\n2. ���󽽶��̽�, ��Ʈ�� �÷��ش�",
		"< ���緹���̵� >\n\n1. 24oz��->����ǻ�� 1.5����, ���� ť��ҽ÷�(���������� ���� �÷�) 2����\n->���� ����->���̴�->�����ش�\n2. ���� �����̽�, ��Ʈ�� 1�� �÷��ش�",
		"< �ڸ����̵� >\n\n1. 24oz��->�ڸ�ǻ��, �ڸ��÷�, �����÷� ���� 1����\n->���� ����->���̴�->�����ش�\n2. �ڸ� �����̽�, ��Ʈ�� 1�� �÷��ش�",
		"< ü���� >\n\n1. 24oz��->ü�����̽� 100ml\n->���� ����->�ݶ�->�����ش�\n2. ��Ʈ�� 1�� �÷��ش�",
		"< ���ӿ��̵� >\n\n1. 24oz��->���Ӻ��̽� 100ml(�� �ؼ�����)\n2. ���ӽ����̽� 4��->�����ش�\n3. ���� ����->���̴� ����->�����ش�\n4. ��Ʈ�� 1�� �÷��ش�",
		"< �ް����̵� >\n\n1. 24oz��->�ް����̵� �÷� 1����(15ml) + ���Ӻ��̽�(85ml) = �� �ؼ�(100ml)\n2. �ڸ�1(4���), ����2, ����2 �ְ� �����ش�\n3. ���� ����->���̴� ����->�����ش�\n4. ��Ʈ �� 1�� �÷��ش�",
		//2����
		"< ���̽� ��Ʈũ�� ���� >\n\n1. 20oz��->��Ʈ�÷� 3����->���ں��̽� 75ml �� �ؼ�����->\n����->���� 200ml->�����ش�\n2. ��Ʈ����->����ũ��ġ",
		"< ���̽� ���������� �� >\n\n1. ������->���� 200ml, ���ں��̽� 50ml->���������� 3��\n->������ư 5�ʰ� �ͽ�(���� �ȳ����ϱ� ����)\n2. 20oz��->����->���빰 �ֱ�->����ũ��\n->������ ���� 1�� ��Ʋ�->��Ű����",
		"< ���̽� ������� �� >\n\n1. 20oz��->������� 200ml(������ ����)->�����÷� 3����\n->����->���� ����->�����ش� ",
		"< ���̽� ����Ƽ��̼� �� >\n\n1. �跮��->���� 200ml, ����ǻ�� 1����, Ƽ��̽� �ҽ� 1����->�����ش�\n2. 20oz��->����->���빰 �װ�->����ũ��\n->ġ��ť�� 4��->ġ�� ���� ���ھ��Ŀ��->����ũ��ġ",
		"< ���̽� ������ >\n\n1. 20oz��->�������̽� 75ml(�� �ؼ�)\n->����->����->�����ش�",
		"< ���̽� ���ڶ� >\n\n1. 20oz��->���ں��̽� ETC���� ->\n���� ���� �Ʒ������� �ְ�->�ټ��� ������ ����",
		"< ���̽� �ް����� >\n\n1. 20oz��->���ں��̽� ETC���� ->\n���� �ΰ� �������� �ְ�->�ټ��� ������ ����\n2. ����->���ڵ帮��, ļ���帮��, ����ũ��ġ",
		"< ���̽� �������� >\n\n1. ������->���� 200ml, ������ǻ�� 1���� -> 1������ ����\n2. 20oz��->����->�ξ��ش�",
		"< ���̽� ��� >\n\n1. ������->���� 250ml, �����Ŀ�� 4���� -> 1������ ����\n2. 20oz��->����->�ξ��ش�",
		"< ���̽� ���ǳӶ� >\n\n1. ������->���� 250ml, ���ǳ� 4���� -> 1������ ����\n2. 20oz��->����->�ξ��ش�",
		"< ���̽� �ξ� ��ũƼ >\n\n1. ������->���� 200ml, ȫ���Ŀ�� 2���� -> 1������ ����\n2. 20oz��->����->�ξ��ش�",
		"< ���̽� ������ >\n\n1. 24oz��->����û 6����\n->�߰ſ� ��(100ml)->�����ְ�->���� �ݸ� �ְ�->�����ְ�\n->���� ���� �ְ�->�� �ְ�(100ml)->�����ְ�\n3. ��Ʈ�� 1�� �÷��ֱ�",
		"< ���̽� ������ >\n\n1. 24oz��->����û 4����\n->�߰ſ� ��(100ml)->�����ְ�->���� �ݸ� �ְ�->�����ְ�\n->���� ���� �ְ�->�� �ְ�(100ml)->�����ְ�\n2. ���󽽶��̽� 1��, ��Ʈ�� 1�� �÷��ֱ�",
		"< ���̽� ��������� >\n\n1. 24oz��->����û 2����, ����û 1����\n->�߰ſ� ��(100ml)->�����ְ�->���� �ݸ� �ְ�->�����ְ�\n->���� ���� �ְ�->�� �ְ�(100ml)->�����ְ�\n2. ���󽽶��̽� 1��, ��Ʈ�� 1�� �÷��ֱ�",
		"< ���̽� �ڸ��� >\n\n1. 24oz��->�ڸ�û 4����\n->�߰ſ� ��(100ml)->�����ְ�->���� �ݸ� �ְ�->�����ְ�\n->���� ���� �ְ�->�� �ְ�(100ml)->�����ְ�\n2. �ڸ������̽� 1��, ��Ʈ�� 1�� �÷��ֱ�",
		"< ���̽� ��׷��� ĳ���� ���۹�Ʈ >\n\n1. �跮��->�߰ſ� ��(150ml)->Ƽ�� 2�� �츮��\n2. 24oz��->���� �� ä���->Ƽ�鹰 �ְ�->�����ְ�\n->���� ���� �ְ�->�� �ְ�(100ml)->�����ְ�\n3. �츰 Ƽ�� 2��, ��Ʈ�� 1�� �Ⱦ��ֱ�",
		"< ��� ������ >\n\nHOT(20z) : 20¥�� �������� -> ����û 4���� -> �߰ſ� �� ���� -> �����ְ�\n-> ���Ƽ�� 3�а� �������\n\nICE(24oz) : �跮�� -> �߰ſ� �� (75ml)�� ���Ƽ�� 3�а� �츮��\n-> 24oz �ÿ�����-> ����û 4����, �� �츰 �� -> �����ְ�\n-> ���� �ְ� -> �� �ְ� -> �����ֱ�\n-> �츰 Ƽ��, ��Ʈ�� 1�� �÷��ֱ�",
		"< ��� �ڸ� ����Ƽ >\n\nHOT(20z) : 20¥�� �������� -> �� 1����(���), �ڸ�û 3����(�ڸ�) -> �߰ſ ���� -> �����ְ�\n-> ��׷��� Ƽ�� (����Ƽ) 3�а� �������\n->�ڸ������̽� 1��(4���), ��ð� �츮�� �����ϱ� Ƽ�� �����ϰ� ��ö�� �ȳ�\n\nICE(24oz) : �跮�� -> �߰ſ� �� (75ml)�� ��׷���Ƽ�� 3�а� �츮��\n-> 24oz �ÿ����� -> �� 1����, �ڸ�û 3����, �� �츰 �� -> �����ְ�\n-> ���� �ְ� -> �� �ְ� -> �����ֱ�\n-> �츰 Ƽ��, �ڸ������̽� 1��, ��Ʈ�� 1�� �÷��ֱ�",
		"< ���� ��Ű ������ >\n\n1. ������ -> ��Ű���̽� ����100 100-> ���� ���� -> 1������ �����ֱ�\n2. ���µ��� 20oz�� -> ��Ű���� 2����\n3. ������ ���� �ҽ� 2���� �ְ� ������ ���⵵�� �����ְ� �ٷ� �ξ��ְ� -> ����ũ��\n-> ��Ű����",
		"< ���� ������ >\n\n1. ������ -> �� 100ml -> ���� ���̽� 100�׶�-> ���� ����\n -> 1������ �����ֱ�\n2. 20oz�� -> ���⸮ġ �������̽� ETC �ؼ����� -> ���빰 �ױ�\n-> ������Ŭ�ͽ� ��ü������ �ѷ��ֱ� ",
		"< ��ġ���� ������ >\n\n1. ������ -> �� 125ml -> ������ ���̽� 100�׶� -> ���� ����\n-> 1������ �����ֱ�\n2. 20oz�� -> ���⸮ġ �������̽� �� �ؼ����� -> ���빰 �ױ�\n-> �Ѳ� ���� ��������� ���Ϸ� �����ֱ�",
		"< �����ֽ� >\n\n1. ������ -> ���� ���̽� 250ml (�ݵ�� ��� ���) -> ���� ���� -> \n1������ �����ֱ�\n2. 20oz�� -> ���� ���� -> ���빰 �ױ�\n-> ��Ʈ�� �÷��ֱ�",
		"< ��� ���� ������ >\n\n1. ������ -> �� 150ml -> ������ ���̽� 90�׶�, �ص����� 50ml -> ���� (���� ��)\n-> 1������ �����ֱ�\n2. 20oz�� -> ���빰 �װ� -> ������Ʈ�ο� ����",
		"< ���ڳ� Ŀ�� ������ >\n\n1. ������ -> ���ڳ� ���̽� 250ml -> ���� (���� ��)\n-> 1������ �����ֱ�\n2. 20oz�� -> ������ 50ml, ���빰 �ξ��ֱ�\n-> ���ڳ�Ĩ ���� 1���� -> ������Ʈ�ο� ����",
		"< ����ٳ��� �ֽ� >\n\n1. ������ -> ���� 200ml, �������̽� 25ml -> �����Ŀ�� 3����, �ٳ��� 1��\n-> 3������ �����ֱ�\n2. 20oz�� -> ���� 8�� -> ���빰 �ξ��ֱ�",
		"< ���� �ֽ� >\n\n1. ������ -> ���� 100ml, �������̽� 75ml -> Ȧ���� 100ml, �ٳ��� 1��\n-> 3������ �����ֱ�\n2. 20oz�� -> ���� 8�� -> ���빰 �ξ��ֱ�",
		"< �����ֽ� >\n\n1. ������ -> �� 100ml, �������̽� 25ml -> ������� 150ml,  Ȧ���� 50ml\n-> 3������ �����ֱ�\n2. 20oz�� -> ���� 8�� -> ���빰 �ξ��ֱ�",
		"< �ʹ� �ֽ� >\n\n1. ������ -> ���� 150ml, ���ں��̽� 100ml -> �ٳ��� �Ŀ�� 1����, �ٳ��� 1��\n-> 3������ �����ֱ�\n2. 20oz�� -> ���� 8�� -> ���빰 �ξ��ֱ�",
		"< ��� ������ >\n\n1. ���� -> �� 1����, �߰ſ� �� �� �� (250ml)\n2. 20oz�� -> ���� ������ �� -> ��� ���̽� �� ���� ���ַ� 2���� �����ֱ�\n-> ���� ���� -> ���� ����",
		"< ��� ���� ��ũƼ �� >\n\n1. ���� -> �� 1����, �߰ſ� �� �� �� (250ml)\n2. 20oz�� -> ��ũƼ �÷� 1����, ���� ������ �� -> ��� ���̽� �� ���� ���ַ� 2���� �����ֱ�\n-> ���� ���� -> ���� ����",
		"<  ��� ���� �׸�Ƽ �� >\n\n1. ���� -> �� 1����, �߰ſ� �� �� �� (250ml)\n2. 20oz�� -> ���� ������ �� , ��� ���̽� 2���� �� ���� ���ַ� �����ֱ�\n3. �跮�� -> ���� 150ml, �������̽� 50ml -> �����ֱ�\n4. ���� ���� -> ���빰 �ξ��ֱ�",
		"< ��� �� >\n\n1. 20oz�� -> ��� ���̽� 3���� �� ���� ���ַ� �����ֱ�\n-> ���� ���� -> ���� ����",
		"< ��� ��ũƼ�� >\n\n1. 20oz�� -> ��ũƼ �÷� 2����, ��� ���̽� 2���� �� ���� ���ַ� �����ֱ�\n-> ���� ���� -> ���� ����", 
		//3����
		"< ���̽� �Ƹ޸�ī�� >\n\n1. �� ����\n2. 24oz��->����->��->�� ",
		"< ���̽� ī��� >\n\n1. �� ����\n2. 20oz��->����->����->��",
		"< ���̽� �ܾƸ޸�ī�� >\n\n1. �� �ܿ� �� 2����->���������� ����\n2. 24oz��->����->��->�� ��� �װ�\n->��ü������ �ѹ� �� �����ֱ�",
		"< ���̽� ������� �Ƹ޸�ī�� >\n\n1. �� �ܿ� ������� �÷� 4����->���������� ����\n2. 24oz��->����->��->�� ��� �װ�\n->��ü������ �ѹ� �� �����ֱ�",
		"< ���̽� �ٴҶ� �Ƹ޸�ī�� >\n\n1. �� �ܿ� �ٴҶ� �÷� 4����->���������� ����\n2. 24oz��->����->��->�� ��� �װ�\n->��ü������ �ѹ� �� �����ֱ�",
		"< ���̽� �ٴҶ� �� >\n\n1. �� �ܿ� �ٴҶ� �÷� 4����->���������� ����\n2. 20oz��->����->����->�� ��� �װ�\n->��ü������ �ѹ� �� �����ֱ�",
		"< ���̽� ť��� >\n\n1. (�� �ܿ� ���� 2����)->���������� ����\n2. 20oz��->����->���� 175ml(ťƼīļ)->�� ��� �װ�\n->��ü������ �ѹ� �� �����ֱ�\n->���ξ��� 2�� �÷��ֱ�",
		"< ���̽� Ƽ��̼��� >\nn1. (�� �ܿ� Ƽ��̽� �ҽ� 1.5����, �����÷� 1����)->���������� ����\n2. 20oz��->����->����(ťƼ��ļ 175ml)->�� ��� �װ�\n->��ü������ �ѹ� �� �����ֱ�\n->Ƽ��̼�ũ�� 1cm �ø���->���ھ� �Ŀ��",
		"< ���̽� īǪġ�� >\n\n1. ( ���̽� ��ǰ��� ���� ��ǰ ����� )\n2. �� ����\n2. 20oz�� -> ���� -> ���� (ťƼ��ļ 175ml) īǪġ�� ��������\n-> ���ְ� -> ��ǰ �ְ� -> �ó��󰡷� (���û���)",
		"< ���̽� ļ��� �����ƶ� >\n\n1. ( ���̽� ��ǰ��� ���� ��ǰ ����� )\n2. �� �ܿ� ļ��� �÷� 4���� -> ���������� ����\n3. 20oz�� -> ���� -> ���� (ťƼ��ļ 175ml) īǪġ�� ��������\n-> ��ǰ���� �ְ� -> �� ��� ����� �ξ��ְ�\n-> ļ��� �帮��",
		"< ���̽� ī���ī >\n		\n1. ( �� ���� )\n2. 20oz�� -> ���ں��̽� 75ml\n-> ���� -> ���� -> �� -> ��ü������ �����ش� -> ����ũ��\n-> ���� �帮�� ���׶��� �ø���",
		"< ���̽� ļ��� ī���ī >\n\n1. ( �� ���� )\n2. 20oz�� -> ļ��� �÷� 2���� + ���ں��̽� 55ml = 75ml\n3. ���� -> ���� -> �� -> ��ü������ �����ش� -> ����ũ��\n-> ļ��� �帮�� ���׶��� �ø���",
		"< ���̽� ��Ʈ ī���ī >\n\n1. ( �� ���� )\n2. 20oz�� -> ��Ʈ �÷� 3���� -> ���ں��̽� �� �ؼ�����\n3. ���� -> ���� -> �� -> ��ü������ �����ش�\n-> ��Ʈ���� -> ���� ũ��ġ",
		"< �ݵ��� Ŀ�� HOT >\n\n1. 20¥�� ������ �� -> �ݵ��� ���� 100ml (�跮��) -> �߰ſ 400ml",
		"< �ݵ��� �� HOT >\n\n1. 20¥�� ������ �� -> �ݵ��� ���� 100ml (�跮��) -> �������� 80��¥�� 250ml",
		"< �ݵ��� ���� (���ν����) HOT >\n\n1. 16¥�� ������ �� -> �ݵ��� ���� 75ml (�跮��) -> �߰ſ 250ml\n-> ������ �����÷� 2���� ������ �ְ�\n-> ���ν���� ũ�� 3��Ǭ ��� �ξ��ְ�\n-> ���� �������� �Ѳ� ���� ���� ���� ���õ���",
		"< �ݵ��� Ŀ�� ICE >\n\n1. 20oz�� -> �ݵ��� ���� 75ml ->\n���� -> �� -> ����",
		"< �ݵ��� �� ICE>\n\n1. 20oz�� -> �ݵ��� ���� 75ml ->\n���� -> ���� -> ����",
		"< �ݵ��� ���� (���ν����) ICE >\n\n1. �跮�� -> �ݵ��� ���� 75ml, �� 125ml, �����÷� 1.5���� -> �ִ��� ���� ������ �ʰ� ���\n2. 16oz�� -> ���� 8�� -> ū ��Ǭ���� ���鿡 �ξ ���� �Ȼ����\n-> ���ν���� ũ�� 3��Ǭ ��� �ξ��ְ�\n-> ���� �������� �Ѳ� ���� ���� ���� ���õ���",
	};
	int start[MAX_DAY_NUM] = {1, 24, 57};
	int end[MAX_DAY_NUM] = {23, 56, 75};
	random_device r;
	mt19937 gen(r());
	uniform_int_distribution<int> dis(0, MAX_MENU_NUM-1);
	int num = 0;
	char select =' ';
	bool retry = false;
	while (true) {
		num = dis(gen);
		cout << "Q. "<< menu[num] << "��(��) �����Ͻÿ�" << endl;
		int select = (int)getchar();
		if (!isDayPractice(select))
		{	
			cout << "======================================" << endl;
			cout <<"A. "<<answer[num] << endl;
			cout << "======================================" << endl << endl << endl;
			/*select = (int)getchar();
			if (!isDayPractice(select))
				;
			else
				doDayPractice(select - 48, menu, answer, start, end);*/
		}
		else
			doDayPractice(select-48, menu, answer, start, end);

	}
	return 0;
}
bool isDayPractice(int select)
{
	if (select == 10)
		return false;
	else
		return true;
}
bool isQuit(int select)
{
	if (select != 113)
		return false;
	else
		return true;
}
void doDayPractice(int day, string* menu, string* answer, int* start, int* end) {
	cout <<endl<<endl<<"<<<<< "<< day << "���� �н��� �����մϴ�" <<" >>>>>"<<endl<<endl<<endl;
	getchar();
	for(int i=start[day-1]-1;i<end[day-1];i++)
	{
		cout <<i-start[day-1]+2<<". "<< menu[i] << "��(��) �����Ͻÿ�" << endl;
		if (isQuit(getchar()))
			break;
		cout << "======================================" << endl;
		cout << "A. " << answer[i] << endl;
		cout << "======================================" << endl << endl;
		/*if (isQuit(getchar()))
			break;*/
	}
	cout <<"<<<<< "<< day <<"���� �н��� �������ϴ�" <<" >>>>>"<< endl << endl << endl;
	getchar();
	return;
}