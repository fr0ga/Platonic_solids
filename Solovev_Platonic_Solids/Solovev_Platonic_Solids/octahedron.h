// �������: �������� ������
// ������: ���122(2)
// ������� 5: 3D ������������� ��� �������� � ���������� ���
// ����: 23.10.2015
// ����� ����������: Visual Studio 2013
// ����������� ��������� ��������, ������, ���������������
// � ������������� ��� �������� � ���������� ���.

const int vcount_oct = 6;
const int icount_oct = 24;
const int size_oct = 180;

const float vertices_oct[vcount_oct][3] = {
	{ 0.0f * size_oct, 0.0f * size_oct, 0.70710678f * size_oct },
	{ 0.0f * size_oct, 0.0f * size_oct, -0.70710678f * size_oct },
	{ 0.0f * size_oct, -0.70710678f * size_oct, 0.0f * size_oct },
	{ -0.70710678f * size_oct, 0.0f * size_oct, 0.0f * size_oct },
	{ 0.0f * size_oct, 0.70710678f * size_oct, 0.0f * size_oct },
	{ 0.70710678f * size_oct, 0.0f * size_oct, 0.0f * size_oct }
};

const int indices_oct[icount_oct] = {
	0, 3, 2,
	0, 4, 3,
	0, 5, 4,
	0, 2, 5,
	1, 5, 2,
	1, 4, 5,
	1, 3, 4,
	1, 2, 3,
};
