#include<windows.h>
//切记！当调用<windows.h>时，不要调用MFC！（Afx.h)
int main()
{
    int result = MessageBox( NULL , TEXT("this is windows") , TEXT("hello") , MB_ICONINFORMATION|MB_YESNO);
    switch(result)/*注意！使用Unicode应用TEXT包围字串*/
    {
        case IDYES:MessageBox(NULL,TEXT("you choose yes"),TEXT("YES"),MB_OK);break;
        case IDNO:MessageBox(NULL,TEXT("you choose no"),TEXT("NO"),MB_OK);break;
    }
    return 0;
}