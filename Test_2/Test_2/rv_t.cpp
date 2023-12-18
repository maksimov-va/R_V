/*!
 * @file rv.cpp
 * @brief Класс РВ (радиовысотомера)
 * @copyright АО ОКБ "Электроавтоматика", НИЦ-1
 * @details
 * #### Файл-спецификация
 *    rv.h
 * #### Номер ВИДК
 *    нет
 * #### Комментарии
 *    нет
 */
#include "rv_t.h"

 //! РВ
rv_t rv;

//! Адреса выходных слов данных (неинвертированные)
const unsigned char rv_t::out_words_addresses[out_words_count] = { 0340 };

//! Обрабатывает событие изменения параметра "Контроль РВ"
static par_change_handler_t out_test_change_handler;

/*!
 * Класс РВ (радиовысотомера, конструктор)
 */
rv_t::rv_t() :
    out_words{},
    out_altitude_test_value(15) {
    out_test->add_change_handler(out_test_change_handler);
}

/*!
 * Класс РВ (радиовысотомера, деструктор)
 */
rv_t::~rv_t() {
}

/*!
 * Выполняет распаковку
 */
void rv_t::unpack() {
}

/*!
 * Обновляет данные бортовой системы
 */
void rv_t::update() {
    // Статус системы в корневом списке параметров (цвет ссылки перехода на страницу системы)
    name->set_list_status(on->get_value() ? PAR_LIST_STATUS_VALID : PAR_LIST_STATUS_INVALID);

    // Тест-контроль (выполнение)
    if (out_test->get_value()) {
        out_altitude->set_status(PAR_STATUS_TEST);
        out_altitude->set_value(out_altitude_test_value);
    }

    // Определение текущего режима РВ
    if (!on->get_value())
        out_mode->set_value(OUT_MODE_OFF);
    else if (out_test->get_value())
        out_mode->set_value(OUT_MODE_TEST);
    else if (out_altitude->get_valid())
        out_mode->set_value(OUT_MODE_NORMAL);
    else
        out_mode->set_value(OUT_MODE_NO_DATA);
}

/*!
 * Выполняет упаковку
 */
void rv_t::pack() {
    unsigned int* w = out_words;

    // СД 340 Радиовысота
    *w++ =
        (out_altitude->get_status() == PAR_STATUS_TEST ? 01 : out_altitude->get_valid() ? 00 : 10);
    //    pack_u(out_altitude->get_value(), 8192., 26, 12);

    // Проверка количества записанных слов
   // assert(w - out_words == out_words_count);

    // Запись адресов слов и 32-го разряда
    //md_set_addresses(out_words, out_words_addresses, out_words_count, 1);
}

/*!
 * Обрабатывает событие изменения параметра "Контроль РВ"
 * @param par Параметр-источник события
 * @param change_flags Признаки события
 */
static void out_test_change_handler(par_t* par, const par_change_flags_t change_flags) {
    (void)par;
    if ((change_flags & PAR_VALUE_CHANGED) != 0) {
        // Сохранение и восстановление значений, установленных до тест-контроля
        if (rv.out_test->get_value()) {
            rv.out_altitude->save();
        }
        else {
            rv.out_altitude->load();
        }
    }
}
