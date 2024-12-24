#include <iostream>
#include <cmath> // Для математических функций

int main() {
    // Дано
    double a = 10.0, b = 4.0, c = 5.0;          // Длины сторон
    double m_a = 0.2, m_b = 0.2, m_c = 0.2;    // Погрешности сторон

    // Производные
    double dV_da = b * c; // ∂V/∂a
    double dV_db = a * c; // ∂V/∂b
    double dV_dc = a * b; // ∂V/∂c

    // Средняя квадратическая погрешность объема
    double m_V = std::sqrt(
        std::pow(dV_da * m_a, 2) +
        std::pow(dV_db * m_b, 2) +
        std::pow(dV_dc * m_c, 2)
    );

    // Вывод результата
    std::cout << "Средняя квадратическая погрешность объема V: "
              << m_V << " м^3" << std::endl;

    return 0;
}
