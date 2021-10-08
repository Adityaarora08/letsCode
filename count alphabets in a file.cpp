
void alphabets()
{
ifstream fin;
fin.open("out.txt");
char ch;
int count=0;
while(!fin.eof())
{
fin.get(ch);
if(isalpha(ch))
count++;
}
cout<<"Number of alphabets in file are "<<count;
fin.close();
}

