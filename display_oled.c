#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "pico/stdlib.h"
#include "pico/binary_info.h"
#include "inc/ssd1306.h"
#include "hardware/i2c.h"

const uint I2C_SDA = 14;
const uint I2C_SCL = 15;

int main(){
    stdio_init_all();   // Inicializa os tipos stdio padrão presentes ligados ao binário


     // Configuração dos pinos dos botões como entrada com pull-up
     const uint BUTTON_A_PIN = 5;  // Botão A no GPIO 5
     const uint BUTTON_B_PIN = 6;  // Botão B no GPIO 6
     gpio_init(BUTTON_A_PIN);
     gpio_init(BUTTON_B_PIN);
     gpio_set_dir(BUTTON_A_PIN, GPIO_IN);
     gpio_set_dir(BUTTON_B_PIN, GPIO_IN);
     gpio_pull_up(BUTTON_A_PIN);
     gpio_pull_up(BUTTON_B_PIN);

    // Inicialização do i2c
    i2c_init(i2c1, ssd1306_i2c_clock * 9000);
    gpio_set_function(I2C_SDA, GPIO_FUNC_I2C);
    gpio_set_function(I2C_SCL, GPIO_FUNC_I2C);
    gpio_pull_up(I2C_SDA);
    gpio_pull_up(I2C_SCL);

    // Processo de inicialização completo do OLED SSD1306
    ssd1306_init();

    // Preparar área de renderização para o display (ssd1306_width pixels por ssd1306_n_pages páginas)
    struct render_area frame_area = {
        start_column : 0,
        end_column : ssd1306_width - 1,
        start_page : 0,
        end_page : ssd1306_n_pages - 1
    };

    calculate_render_area_buffer_length(&frame_area);

    // zera o display inteiro
    uint8_t ssd[ssd1306_buffer_length];
    memset(ssd, 0, ssd1306_buffer_length);
    render_on_display(ssd, &frame_area);


    char *text[] = {
        "  Bem-vindos,   ",
        "  ao Projeto    ",
        "  Embarcatech   ",
        "  do aluno      ",
        "  Luis Eduardo  ",};

    int y = 0;
    for (uint i = 0; i < count_of(text); i++)
    {
        ssd1306_draw_string(ssd, 5, y, text[i]);
        y += 8;
    }
    render_on_display(ssd, &frame_area);



    while(true) {
        if (gpio_get(BUTTON_A_PIN) == 0){
            const uint8_t bitmap_128x64[] = {
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xc7, 0xc1, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8f, 0xc1, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0x1f, 0xf5, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xf5, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0x07, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x67, 0xc1, 0xff, 0x1f, 0xfc, 
                0xff, 0xff, 0xff, 0x67, 0xc1, 0xff, 0xdc, 0xfd, 0xff, 0xff, 0xff, 0x67, 0xd5, 0xff, 0xd8, 0xfd, 
                0x8f, 0xff, 0xff, 0x07, 0xd5, 0x7f, 0xd2, 0xfd, 0x87, 0x21, 0x0c, 0x17, 0xdd, 0x7f, 0xd7, 0xfd, 
                0x03, 0x21, 0x0c, 0x37, 0xff, 0x7f, 0xf7, 0xff, 0x03, 0x21, 0x0c, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0x03, 0x21, 0x0c, 0xf7, 0xc1, 0xff, 0x37, 0xfc, 0x03, 0x21, 0x0c, 0xf7, 0x5d, 0xf0, 0xb1, 0xfd, 
                0x03, 0x21, 0x0c, 0x07, 0x5d, 0xfc, 0x38, 0xfc, 0x07, 0x21, 0x0c, 0x07, 0x5d, 0xfd, 0xf8, 0xff, 
                0x87, 0x21, 0x0c, 0xf7, 0x5d, 0xfd, 0xf0, 0xff, 0x87, 0xff, 0x0f, 0xf7, 0x41, 0xfc, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x10, 0xfc, 0xff, 0x3f, 0xfc, 0x07, 0x7f, 0xf0, 0x5e, 0xff, 
                0x03, 0x21, 0x0c, 0x07, 0xff, 0xff, 0x50, 0xff, 0x03, 0x21, 0x0c, 0x07, 0xc1, 0xf1, 0x5c, 0xff, 
                0x03, 0x21, 0x0c, 0xff, 0xc1, 0xf8, 0x10, 0xfe, 0x03, 0x21, 0x0c, 0xe7, 0x55, 0xfa, 0xff, 0xfc, 
                0x03, 0x21, 0x0c, 0xe7, 0x55, 0xf8, 0xf0, 0xfd, 0x03, 0x21, 0x0c, 0x07, 0xdd, 0xf1, 0xfa, 0xff, 
                0x03, 0x21, 0x0c, 0x07, 0xff, 0xff, 0xfa, 0xff, 0x03, 0x21, 0x0c, 0x07, 0xff, 0xf0, 0x18, 0xfc, 
                0xff, 0xe1, 0xff, 0xe7, 0xc1, 0xf7, 0x5f, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xf1, 0xf7, 0x50, 0xff, 
                0x07, 0x3e, 0xf8, 0xff, 0xf5, 0xf0, 0x57, 0xff, 0x07, 0x3e, 0xf8, 0x07, 0xf5, 0xff, 0x17, 0xfe, 
                0x07, 0x3e, 0xf8, 0x07, 0xe1, 0xff, 0xf0, 0xfc, 0x07, 0x3e, 0xf8, 0x3f, 0x5f, 0xf0, 0xff, 0xfd, 
                0x07, 0x3e, 0xf8, 0x3f, 0xff, 0xff, 0xf7, 0xff, 0x07, 0x3e, 0xf8, 0x3f, 0xcf, 0xff, 0xf3, 0xff, 
                0x07, 0x3e, 0xf8, 0x07, 0xe3, 0xff, 0x10, 0xfc, 0x07, 0x3e, 0xf8, 0x07, 0xe9, 0xff, 0x5e, 0xfd, 
                0x07, 0x3e, 0xf8, 0xff, 0xed, 0xff, 0x5f, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xe9, 0xff, 0x7f, 0xff, 
                0xff, 0xff, 0xff, 0xe7, 0xe3, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xe7, 0xff, 0x1f, 0xfc, 
                0xff, 0xff, 0xff, 0x07, 0xcf, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0x7f, 0xfe, 
                0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0x1f, 0xfc, 0xff, 0xff, 0xff, 0xe7, 0xc1, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdf, 0xff, 0xef, 0xff, 
                0xff, 0xff, 0xff, 0x03, 0xde, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0x03, 0xfe, 0xff, 0x0f, 0xfc, 
                0xff, 0xff, 0xff, 0x73, 0xfe, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0x73, 0xfe, 0xff, 0xef, 0xff, 
                0xff, 0xff, 0xff, 0x73, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x73, 0xfe, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0x03, 0xfe, 0xff, 0x0f, 0xfc, 0xff, 0xff, 0xff, 0x03, 0xfe, 0xff, 0xaf, 0xfd, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xaf, 0xfd, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xaf, 0xfd, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
                0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff
            };
        
            ssd1306_t ssd_bm;
            ssd1306_init_bm(&ssd_bm, 128, 64, false, 0x3C, i2c1);
            ssd1306_config(&ssd_bm);
        
            ssd1306_draw_bitmap(&ssd_bm, bitmap_128x64);

        }else if (gpio_get(BUTTON_B_PIN) == 0){
            const uint8_t bitmap_128x64[] =  {
                0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x06, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x0e, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x0e, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x1e, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x1e, 0x10, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x3e, 0x1e, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0xfe, 0x0f, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0xfe, 0x0f, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0xfe, 0x0f, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0xff, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xff, 0x03, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xf8, 0xff, 0x03, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xf8, 0xff, 0x03, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xf0, 0xff, 0x03, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x80, 0xff, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0xfe, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0xfe, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0xfe, 0x0f, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0xbe, 0x1f, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x1e, 0x18, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x1e, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x1e, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x0e, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x06, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0x00, 0x00, 0x00, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xc0, 0x81, 0x03, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 
                0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83, 0xe0, 0xc3, 0x07, 0x1f, 0x7c, 0xf0, 0xc1, 0x83
            };
            
        
            ssd1306_t ssd_bm;
            ssd1306_init_bm(&ssd_bm, 128, 64, false, 0x3C, i2c1);
            ssd1306_config(&ssd_bm);
        
            ssd1306_draw_bitmap(&ssd_bm, bitmap_128x64);
        }

        
    }

    return 0;
}