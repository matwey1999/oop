#ifndef ALGORITHMS_HPP
#define ALGORITHMS_HPP

#include "myvector.hpp"
#include "mysharedptr.hpp"
#include "myfigures.hpp"


void PrintVectorOfShapes(const my_impl::vector<my_impl::shared_ptr<Shape>>& vector);

my_impl::vector<my_impl::shared_ptr<Shape>> FillContainerWithRandShapes(size_t size);

//Проверка двух неупорядоченных диапазонов на равенство по определенному критерию.
bool CheckRangesForEq(const my_impl::vector<my_impl::shared_ptr<Shape>>& vec,
        size_t pos1_1, size_t pos1_2, size_t pos2_1, size_t pos2_2);

void PrintInfoAboutEq(const my_impl::vector<my_impl::shared_ptr<Shape>>& vec,
        size_t pos1_1, size_t pos1_2, size_t pos2_1, size_t pos2_2);

//Удалить элементы, удовлетворяющие заданному критерию.
void DelElements(my_impl::vector<my_impl::shared_ptr<Shape>>& vec);

#endif //ALGORITHMS_HPP