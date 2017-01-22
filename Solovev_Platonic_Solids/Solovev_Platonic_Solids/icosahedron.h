// Студент: Соловьев Андрей
// Группа: БПИ122(2)
// Семинар 5: 3D моделирование тел вращения и платоновых тел
// Дата: 23.10.2015
// Среда разработки: Visual Studio 2013
// Реализованы алгоритмы вращения, сдвига, масштабирования
// и проецирования тел вращения и платоновых тел.

const int vcount_icos = 12;
const int icount_icos = 60;
const int size_icos = 100;

const float vertices_icos[vcount_icos][3] = {
	{ 0.0f * size_icos, -1.61803398875f * size_icos, 1.0f * size_icos },
	{ 0.0f * size_icos, 1.61803398875f * size_icos, 1.0f *  size_icos },
	{ 0.0f * size_icos, 1.61803398875f * size_icos, -1.0f * size_icos },
	{ 0.0f * size_icos, -1.61803398875f * size_icos, -1.0f * size_icos },

	{ 1.0f * size_icos, 0.0f * size_icos, 1.61803398875f * size_icos },
	{ -1.0f * size_icos, 0.0f * size_icos, 1.61803398875f * size_icos },
	{ -1.0f * size_icos, 0.0f * size_icos, -1.61803398875f * size_icos },
	{ 1.0f * size_icos, 0.0f * size_icos, -1.61803398875f *  size_icos },

	{ 1.61803398875f * size_icos, 1.0f * size_icos, 0.0f * size_icos },
	{ -1.61803398875f * size_icos, 1.0f * size_icos, 0.0f * size_icos },
	{ -1.61803398875f * size_icos, -1.0f * size_icos, 0.0f * size_icos },
	{ 1.61803398875f * size_icos, -1.0f * size_icos, 0.0f * size_icos }
};

const int indices_icos[icount_icos] = {
	0, 10, 5,
	0, 5, 4,
	0, 4, 11,
	0, 11, 3,
	0, 3, 10,
	2, 6, 7,
	2, 7, 8,
	2, 8, 1,
	2, 1, 9,
	2, 9, 6,
	6, 10, 9,
	9, 10, 5,
	9, 5, 1,
	5, 4, 1,
	1, 4, 8,
	4, 11, 8,
	8, 11, 7,
	11, 3, 7,
	7, 3, 6,
	3, 10, 6
};
