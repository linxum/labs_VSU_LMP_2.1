//��� ��������� ���� input.txt, � ������� �������� ����� �����. ������� ������������� �� ��� -
//�������� ������.�� ������ ������ ������ ������ ������ ����� ��������� ������ ����(�� -
//����������� �������).���������� ������������������ �������� � ��������� ����
//output.txt.���� ������� ����� ���, �� ������ ������������������ � ���� �������� ������� -
//�������� ���������.

#include "My_List.h"
#include <Windows.h>

bool task(LIST& list)
{
	auto isEqual = [](int first, int second)
	{
		return first == second;
	};
	bool check = false;
	ptrNODE p = list.get_head();
	while (p->next && p->next->next)
	{
		bool flag = true;
		if (isEqual(*p->next->info, *p->next->next->info))
		{
			list.del_after(p->next);
			flag = false;
		}
		if (flag)
		{
			p = p->next;
		}
		if (!flag)
		{
			check = true;
		}
	}
	return check;
}

int main()
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	bool flag = true;
	while (flag)
	{
		LIST list;
		std::ifstream file_in("input.txt");
		std::ofstream file_out("output.txt");
		if (file_in)
		{
			bool input = true;
			while (input)
			{
				char choice;
				std::cout << "��������, ��� ����� ����������� ������ (1 - ����, 2 - �������, 3 - ������������): "; std::cin >> choice;
				switch (choice)
				{
				case '1':
					list.create_by_stack(file_in);
					input = false;
					break;
				case '2':
					list.create_by_queue(file_in);
					input = false;
					break;
				case '3':
					list.create_by_order(file_in);
					input = false;
					break;
				default:
					std::cout << "�������� ����" << std::endl;
					input = true;
					break;
				}
			}
			if (task(list))
			{
				list.print(file_out, "��������������� ������������������: \n");
			}
			else
			{
				list.print(file_out);
			}
		}

		file_in.close();
		file_out.close();

		char choice;
		bool label = true;
		while (label)
		{
			std::cout << "������� ������ ������ ��� �����? 1 - ������, 2 - ����� ";
			std::cin >> choice;
			switch (choice)
			{
			default:
				std::cout << "�������� ����!" << std::endl;
				label = true;
				break;
			case '1':
				flag = true;
				label = false;
				break;
			case '2':
				flag = false;
				label = false;
				break;
			}
		}
	}
	std::cin.ignore();
	std::cin.get();
}