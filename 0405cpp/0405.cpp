#include <iostream>

// std��� ������ �ְ� �װ��� ::�� �����͸� ���ٴ°�.
// ������ �̸��������� ���ؼ� �����͸� �����Ѵ�.
// �ڵ带 ��ĥ �� ������ �̸��� ��ġ�� ��츦 ���ϴ� ����̴�.
int ii = 10;

namespace A
{
	void exFunc()
	{
		std::cout << "A�� ������ �Լ�\n" << std::endl;
	}
}

namespace B
{
	void exFunc()
	{
		std::cout << "A�� ������ �Լ�\n" << std::endl;
	}
}

namespace myNamespace1
{
	int a;

	void doSomething() {}

	namespace AA
	{
		namespace BB
		{
			namespace CC
			{
				int c;
			}
		}
	}
}

namespace myNamespace2
{
	int a;

	void doSomething() {}

	namespace AA
	{
		namespace BB
		{
			namespace CC
			{
				int c;
			}
		}
	}
}

int main()
{
	A::exFunc();
	B::exFunc();

	myNamespace1::AA::BB::CC::c;

	{
		using namespace myNamespace1;
		// using namespace myNamespace2;

		a = 10; // ambiguity ��ȣ�� ����, �ΰ��Ǻ����� �������� ����� �� ����.

		myNamespace2::a = 20;
	}

	using std::cin;
	using std::cout;
	using std::endl; // std�� �Ⱥ��̰� ����ʹٸ�, ���Ͱ��� �ϳ��ϳ� �ᵵ�ǰ�,

	using namespace std; // std�� �Ⱥ��̰� ����ʹٸ�, �ѹ濡 �ٿ����ȴ�.

	cout << "hello" << endl;

	int ii = 0;
	ii++;

	cout << ii << endl;
	// ���������� ����Ǿ��� �� ���������� ������ ���������� �켱�Ǽ� ��Ÿ����.
	// ���������� ����ϰ� �ʹٸ�, �ذ����� Ȱ���� �� �ִ�.
	::ii++;
	cout << ::ii << endl;

	return 0;
}