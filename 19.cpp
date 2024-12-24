#include <iostream>
#include <cmath> // Для математических функций

int main() {
    // Дано
    double k = 100.0, m_k = 0.1;
    double l = 100.0, m_l = 0.05;
    double c = 0.31, m_c = 0.02;
    double v_deg = -12.5, m_v_deg = 0.0167;

    // Перевод угла в радианы
    double v = v_deg * M_PI / 180.0;
    double m_v = m_v_deg * M_PI / 180.0;

    // Считаем sin(v) и cos(v)
    double sin_v = std::sin(v);
    double cos_v = std::cos(v);

    // Значение поправки ΔS
    double delta_S = (k * l + c) * std::pow(sin_v, 2);

    // Частные производные
    double dS_dk = l * std::pow(sin_v, 2);
    double dS_dl = k * std::pow(sin_v, 2);
    double dS_dc = std::pow(sin_v, 2);
    double dS_dv = 2 * (k * l + c) * sin_v * cos_v;

    // Средняя квадратическая погрешность
    double m_delta_S = std::sqrt(
        std::pow(dS_dk * m_k, 2) +
        std::pow(dS_dl * m_l, 2) +
        std::pow(dS_dc * m_c, 2) +
        std::pow(dS_dv * m_v, 2)
    );

    // Вывод результата
    std::cout << "Поправка ΔS: " << delta_S << " м" << std::endl;
    std::cout << "Средняя квадратическая погрешность ΔS: " << m_delta_S << " м" << std::endl;

    return 0;
}
