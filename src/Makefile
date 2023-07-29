.PHONY: all dist install uninstall dist dvi gcov_report clean check rebuild
CXX = g++ -std=c++17
CXXFLAGS = -Wall -Werror -Wextra -g
OS = $(shell uname -s)
TEST_FLAGS = -o test.out -lgtest

ifeq ($(OS), Linux)
	TEST_FLAGS += -lpthread
endif

all: test gcov_report check install dvi

test: test.cc
	$(CXX) $(CXXFLAGS) test.cc Model/EnigineeringCalculator/engineering_calculator_facade.cc  Model/EnigineeringCalculator/Calculator/calculator.cc  Model/EnigineeringCalculator/Converter/converter.cc  Model/EnigineeringCalculator/Validator/validator.cc  Model/EnigineeringCalculator/common.h $(TEST_FLAGS)
	./test.out

dvi:
	touch readme.dvi
	@(echo "В данном проекте я реализовал на языке программирования С++ в парадигме объектно-ориентированного программирования расширенную версию обычного калькулятора, реализующую те же самые функции, что и разработанное ранее приложение в проекте SmartCalc v1.0. Помимо базовых арифметических операций, как плюс-минус и умножить-поделить, калькулятор дополнене возможностью вычисления арифметических выражений с учетом приоритетов, а так же некоторыми математическими функциями (синус, косинус, логарифм и т.д.). Помимо вычисления выражений калькулятор так же поддерживает использование переменной x и построение графика соответствующей функции." > readme.dvi)

dist:
	rm -rf archive_smart_calc/
	mkdir archive_smart_calc/
	mkdir archive_smart_calc/src/
ifeq ($(OS), Darwin)
	cp -r ./build/Smart_Calculator.app archive_smart_calc/src/
else
	cp -r ./build/Smart_Calculator archive_smart_calc/src/
endif
	tar cvzf archive_smart_calc.tgz archive_smart_calc/
	rm -rf archive_smart_calc/

install:
	cd View/MainView && qmake && make && make clean && rm Makefile && cd ../ && mkdir ../build
	mv View/MainView/MainView.app ./build
	mv build/MainView.app/Contents/MacOS/MainView build/Calculator && rm -rf build/MainView.app


uninstall:
	rm -rf build*

clean:
	rm -rf build
	rm -rf *.out *.gcda *.gcno *.a *.info *.o report *.dSYM .DS_Store *.dvi
	rm -rf ./model/*.out ./model/*.gcda ./model/*.gcno ./model/*.a ./model/*.info ./model/*.o report ./model/*.dSYM ./model/.DS_Store
	rm -rf ./view/*.out ./view/*.gcda ./view/*.gcno ./view/*.a ./view/*.info ./view/*.o report ./view/*.dSYM ./view/.q* ./view/.DS_Store ./view/moc*
	rm -rf ./controller/*.out ./controller/*.gcda ./controller/*.gcno ./controller/*.a ./controller/*.info ./controller/*.o report ./controller/*.dSYM ./controller/.DS_Store

check:
	clang-format -style=google -n test.cc
	clang-format -style=google -n ./Model/EnigineeringCalculator/Converter/*.cc ./Model/EnigineeringCalculator/Converter/*.h
	clang-format -style=google -n ./Model/EnigineeringCalculator/Validator/*.cc ./Model/EnigineeringCalculator/Validator/*.h
	clang-format -style=google -n ./Model/EnigineeringCalculator/Calculator/*.cc ./Model/EnigineeringCalculator/Calculator/*.h
	clang-format -style=google -n ./Model/EnigineeringCalculator/*.cc  ./Model/EnigineeringCalculator/*.h
	clang-format -style=google -n ./Model/FinanceCalculator/*.cc  ./Model/FinanceCalculator/*.h
	clang-format -style=google -n ./Controller/*.cc ./Controller/*.h
	clang-format -style=google -n ./View/EngineeringCalculator/*.cc ./View/EngineeringCalculator/*.h
	clang-format -style=google -n ./View/FinanceCalculator/*.cc  ./View/FinanceCalculator/*.h
	clang-format -style=google -n ./View/QCustomPlot/*.cc  ./View/QCustomPlot/*.h
	clang-format -style=google -n ./View/MainView/*.cc  ./View/MainView/*.h
	CK_FORK=no leaks --atExit -- ./test.out


rebuild: clean all

