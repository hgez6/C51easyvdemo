   #include<reg51.h>
#define uchar unsigned char;
uchar distab[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71,0x00};  //0��f
void delay(unsigned int a)
{
    unsigned int i,j;
    for(i=0;i<a;i++)
        for(j=0;j<120;j++);
}
uchar kbscan(void)
{
    unsigned char sccode,recode;
    P1=0x0f;  //��0ɨ��,��������
    if ((P2 & 0x0f) !7a686964616fe58685e5aeb931333363396365= 0x0f)  //�м�����
    {
        delay(20);   //��ʱȥ����
        if ((P1&0x0f)!= 0x0f)
        {
            sccode = 0xef;    //����ɨ���ֵ
            while((sccode&0x01)!=0)
            {
                P1=sccode;
                if((P1&0x0f)!=0x0f)
                {
                    recode=(P1&0x0f)|0xf0;
                    while((P1&0x0f)!=0x0f);//�ȴ���̧��
                    return((~sccode)+(~recode));
                 }
                else
                sccode=(sccode<<1)|0x01;
            }
        }
    }
    return 0;  //�޼����£�����0
}
 
uchar getkey(void)
{
    unsigned char key,keyval=0xff;
    key=kbscan();
        switch(key)
        {
        case 0x11:keyval=1;break;
        case 0x12:keyval=2;break;
        case 0x14:keyval=3;break;
        case 0x18:keyval=10;break; //+
        case 0x21:keyval=4;break;
        case 0x22:keyval=5;break;
        case 0x24:keyval=6;break;
        case 0x28:keyval=11;break; //-
        case 0x41:keyval=7;break;
        case 0x42:keyval=8;break;
        case 0x44:keyval=9;break;
        case 0x48:keyval=12;break; //���
        case 0x81:keyval=13;break;
        case 0x82:keyval=0;break;
        case 0x84:keyval=14;break; //С����
        case 0x88:keyval=15;break; //ȷ��
        default:keyval=16;break;
        }
        return(keyval);
}
main()
{
uchar keyin;
        while(1)
        {
        keyin=getkey();
        P0=distab[keyin];
        }
}