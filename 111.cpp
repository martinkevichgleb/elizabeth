#include <iostream>
#include <cmath> // Для математических функций

int main() {
    // Дано
    double S = 50.0, m_S = 0.05;            // Горизонтальное расстояние и его погрешность
    double n_deg = 2.0, m_n_sec = 5.0;      // Угол наклона в градусах и погрешность в секундах

    // Перевод угла и погрешности в радианы
    double n_rad = n_deg * M_PI / 180.0;
    double m_n_rad = (m_n_sec / 3600.0) * M_PI / 180.0;

    // Вычисление производных
    double tan_n = std::tan(n_rad);
    double sec2_n = 1 + std::pow(tan_n, 2);

    double dH3_dS = tan_n;
    double dH3_dn = S * sec2_n;

    // Средняя квадратическая погрешность
    double m_H3 = std::sqrt(
        std::pow(dH3_dS * m_S, 2) +
        std::pow(dH3_dn * m_n_rad, 2)
    );

    // Вывод результата
    std::cout << "Средняя квадратическая погрешность отметки H3: "
              << m_H3 << " м" << std::endl;

    return 0;
}
