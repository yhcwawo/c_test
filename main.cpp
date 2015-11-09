#define _CRT_SECURE_NO_WARNINGS
//scanf���� ����ϹǷ� ���޽����� ������ �ʵ��� �Ѵ�.

//������� ����
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//������ �ʱⰪ ����
int OperatorTop = 0;  
//������ ������ �ʱⰪ
int ValueTop = 0;
//���� ������ �ʱⰪ

char OperatorStack[100]; //���� ������ �迭
char ValueStack[100];  //���� �� �迭




int IsEmptyValueStack()
{
	if (ValueTop == 0)
		return 1;
	else return 0;
}
//�� ���� �迭�� ����ִ� �������� Ȯ���ϴ� �Լ�


int Is_Empty_OperatorStack()
{
	if (OperatorTop == 0)
		return 1;
	else return 0;
}
//������ ���� �迭�� ����ִ� �������� Ȯ���ϴ� �Լ�



void OperatorPush(char opr)
{
	OperatorStack[OperatorTop++] = opr;
}
//������ ���ÿ� �����ڸ� �Է��ϴ� �Լ�
//�Է½� �������� �ʱⰪ�� 1 ������Ų��.


void ValuePush(int value)
{
	ValueStack[ValueTop++] = value;
}
//�� ���ÿ� ���� �Է��ϴ� �Լ�
//�Է½� ���� �ʱⰪ�� 1 ������Ų��.


char OperatorPop()
{
	return OperatorStack[--OperatorTop];
}
//�����ڸ� ������ ���� �Լ�
//��� �����δ� ���� �������� �ִ� �����ڰ� ��ȯ�ȴ�.



int ValuePop()
{
	return ValueStack[--ValueTop];
}

//���� ������ ���� �Լ�
//��� �����δ� ���� �������� �ִ� ���� ��ȯ�ȴ�.







int Priority(char opr1, char opr2)
{
	if (opr1 == '*' || opr1 == '/'){
		if (opr2 == '+' || opr2 == '-')
			return 1;
		else return 0;
	}
	else return 0;
}
//�����̳� �������� ������ �������� �켱�� �Ǿ�� �Ѵ�.
//�׿� ���� ������ �����ִ� �Լ�




int Calculate(int value1, int value2, char opr)
{
	switch (opr){
	case'+':
		value1 = value1 + value2;
		break;
	case'*':
		value1 = value1 * value2;
		break;
	case'/':
		value1 = value2 / value1;
		break;
	}

	return value1;
}
//�� 2���� �Է¹ް� �����ڸ� �Է¹޾����� �������� �ϴ� �Լ�
//�Է��� ��� �� �� 2���� char�� �����ڸ� �Է¹޴´�.


int Calculate2(int value1, int value2, char opr)
{
	switch (opr){
	case'+':
		value1 = value1 + value2;
		break;
	case'*':
		value1 = value1 * value2;
		break;
	case'/':
		value1 = value2 / value1;
		break;
	case'-':
		value1 = value1 - value2;
		break;
	}

	return value1;
}
//Caluetate�Լ��� ��������� �߰� ����ÿ��� ���� ����� Ư�̻����� ����� �ʿ䰡 �����Ƿ�
//switch�� ���� ��Ʈ�� �߰��Ͽ���.
//���̺��� �߰�������, �߰����갪�� ��ǲ���� �ް� ����� ��ȯ�ϴ� �Լ��̴�.



void main()
{
	
	int i=0;  //�⺻���� ī��Ʈ�� ���� ����
	int len;  //�Է¹��� ���ڿ��� ���̸� �����ϴ� ����
	int check_signal = 0;  
	int value1, value2; //������ �Ҷ� �� 2���� ���� ���ؾ� �ϹǷ� ���� ���� ������ 2�� �������ش�.
	int table; //��� ������ �������� ������� �����ϴ� ����
	int count1 = 0;
	int count2 = 0;

	char buf[100]; //strcpy�� �Է¹��� ���ڿ��� �����ϴ� �迭
	char input[100];  //ó���� �Է¹��� ���ڿ��� �����ϴ� �迭
	char opr; //������ ����
	char opr2[100]; //�߰� ����� ���� �����ڸ� �Է� �޴� �迭
	char A; //������ ���躯��
	char temp;//��ȣ ������ ���� ����
	
	int nValue;  //��� ������ �����Ŀ� �߰����� �� �߰� ������ ���� �����ϴ� ����


	printf("----------------------------------------------\n");
	printf("\n������ Ȱ���� ����� �����մϴ�.\n");
	printf("\n----------------------------------------------\n");
  	printf("��ȣ�� �����Ͽ� ��� �� ������ �Է����ּ��� : ");
	scanf("%s", &input);
	//��ȣ�� ������ ������ ���ڿ� ���� ������ �Է¹޾� input�� �����Ѵ�.

	

	strcpy(buf, input);
	//input�� ������ ���ڿ��� buf �迭�� �����Ѵ�.

	len = strlen(buf);
	//buf �迭�� �ִ� ���ڿ��� ���̸� len ������ �����Ѵ�.

	

	//��ȣ�� ���� �´��� Ȯ���ϱ� ���� ����
	//'('�� ')'�� ������ ���� ������ ���� �´��� üũ�Ѵ�.
	for (i = 0; i < len; i++)
	{

		if (input[i] == '(')
		{
			count1 = count1 + 1;
		}


		if (input[i] == ')')
		{
			count2 = count2 + 1;
		}
	}

		if (count1 != count2)
		{
			printf("��ȣ�� ���� ���� �ʽ��ϴ�.\n");
		}
		else
			printf("��ȣ�� ���� ��ġ�մϴ�.\n");

	i=0;
	//i ���� �ٽ� �ʱ�ȭ
		

	while (i<len){
		A = buf[i++];
		//�ݺ����� ���ڿ��� ���� ��ŭ �ݺ��Ѵ�.
		//A������ ���ڿ��� ù ��° ���� �����Ѵ�.

		//���� üũ�ϰ� �ִ� ���ڿ��� ������ ������ ���
		if (A == ' ')  continue;
		else if ('0' <= A && A <= '9')
		{
			//check_signal�� �ʱⰪ�� 0���� �����ִ�.
			//A������ 0~9�� ���� ���� ��� üũ
			//0~9������ ���̶�� �Ǵܵ� ��� ������ �迭�� �����Ѵ�.
			if (check_signal != 1) ValuePush(A - '0');   
			else
			{
				check_signal = 0;
				ValuePush(-(A - '0'));
			}
		}

		//üũ�ϰ� �ִ� ���ڿ��� �������� ����̴�.
		//���� ������ �ִ� ��� signal�� 1�� �����ϰ� ���� �����ڰ��� +�� �����Ѵ�.
		else 
		if (A == '+' || A == '-' || A == '*' || A == '/'){
			if (A == '-')
			{
				check_signal = 1; A = '+';
			}
			

			if (Is_Empty_OperatorStack())
				OperatorPush(A);
			//������ ������ ����ٸ� �����ڸ� �־��ش�.


			else{
				opr = OperatorPop();
				

				//������ ���ÿ� �����ڰ� ������ A�� ������ �����ڿ� ���� ������ ���ð��� ��� �����ڸ� ���� ���� ���Ѵ�.
				if (Priority(opr, A))
				{
					value2 = ValuePop();
					value1 = ValuePop();

					value1 = Calculate(value1, value2, opr);
					ValuePush(value1);
					OperatorPush(A);
				}

				//���� �� ���ÿ� �ִ� ���� ���� ��� �ؾߵǸ� ����ؾ��� ���� pop�ؼ� ����� �� ���ÿ� �ٽ� �����Ѵ�.
			    else{
					OperatorPush(opr);
					OperatorPush(A);
				}
			}
		}

		// ��ȣ�� ������ ������ �ϴ� �ڵ��̴�.
		//'('�� ��Ÿ���� �����ڸ� ������ ')'�������� ���� ����Լ��� ����Ѵ�.
		else if (A == '('){
			OperatorPush(A);
		}
		else if (A == ')'){
			do{
				temp = OperatorPop();
				if (temp != '('){
					value2 = ValuePop();
					value1 = ValuePop();

					value1 = Calculate(value1, value2, temp);
					ValuePush(value1);
				}
			} while (temp != '(');
		}

	}

	//���ÿ� �ִ� ���� ������������ ����� �ݺ��Ѵ�.
	while (!Is_Empty_OperatorStack()){
		value1 = ValuePop();
		value2 = ValuePop();
		opr = OperatorPop();
		value1 = Calculate(value1, value2, opr);
		ValuePush(value1);
	}

	
	
	//�������� pop�� ���� �����Ѵ�.
	table = ValuePop();
	//���� ���� ���̺� �����ϱ� ���ؼ� ���� pop���� ������ ���� �����Ѵ�.


	printf("%s = %d\n", buf, table);
	//���� �����¹�

	int go;
	//�ڿ� ���İ���� �߰��� �������� ���θ� �����ϴ� ����

	printf("���İ���� ��� �Ͻðڽ��ϱ�?(1=yes,0=no)");
	scanf("%d", &go);
	//go ������ ����� �Է¹ް�
	//switch���� ���� �ڵ带 �����Ѵ�.

	
	nValue = 0;
	//�Է¹��� ���� �����ϱ� ���� ���� �ʱ�ȭ
	switch (go)
	{
	case 1:
		//1�� �Է��� ��� �߰� ������ ����
		
		printf("���� ������ ���� %d �Դϴ�.\n",table);

		printf("-------------------------------------------------------\n  ");
		printf("����Ϸ��� �����ڸ��Է����ּ���(ex:+,*,/)   :   ");
		scanf("%s", &opr2);


		printf("����Ϸ��� ���� �Է����ּ���(ex: 12,30,1)   :   ");
		scanf("%d", &nValue);
		printf("\n-------------------------------------------------------\n  ");

		printf("\n�߰� ���� ����� %d �Դϴ�.", Calculate2(table, nValue, opr2[0]));
	
		printf("\n�߰� ���� �Ϸ�");



		break;
	case 0:
		printf("����� �����մϴ�.");
		break;

		//���� ����
	default:
		printf("1�� 0���θ� �Է����ּ���.");
		
	}





}