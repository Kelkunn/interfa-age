#include "lvgl.h"
#include "LEDMatrix.h"

// définition des couleurs (mot clé en anglais)
#define BLACK 0x0000                          // noir
#define BLUE 0x001F                           // Bleu
#define RED 0xF800                            // Rouge
#define GREEN 0x07E0                          // Vert
#define CYAN 0x07FF                           // Cyan
#define MAGENTA 0xF81F                        // Magenta
#define YELLOW 0xFFE0                         // Jaune
#define WHITE 0xFFFF                          // Blanc
#define LV_COLOR_RED LV_COLOR_MAKE(255, 0, 0) // Définir la couleur rouge
int color = 0;
// Déclaration du canvas en tant que variable globale
lv_point_t point, oldPoint;
lv_area_t area;

LEDMatrix ecran(D8, D2, D7, D3, D5, D12, D10, D11, D9, D0, D1, D4, D6);

uint8_t bufferEcran[64 * 32 * 2] = {0};
int gomme=0;
lv_obj_t *btn1; 
lv_obj_t *btn2;
lv_obj_t *btn3; 
lv_obj_t *btn4; 
lv_obj_t *btn5; 
lv_obj_t *btn6; 
lv_obj_t *btn7; 
lv_obj_t *btn8; 
lv_obj_t *btn9; 
lv_obj_t *btn10; 


/*static void event_handler(lv_event_t *e)
{
  lv_event_code_t code = lv_event_get_code(e);

  if (code == LV_EVENT_CLICKED)
  {
    LV_LOG_USER("Clicked");
    color +=1;
  }
  else if (code == LV_EVENT_VALUE_CHANGED)
  {
    LV_LOG_USER("Toggled");
  }
}*/

void bouton1_event_cb(lv_event_t *e)
{

  color = 1; // rouge
  gomme=0;

  lv_obj_clear_state(btn2, LV_STATE_CHECKED);
  lv_obj_clear_state(btn3, LV_STATE_CHECKED);
  lv_obj_clear_state(btn4, LV_STATE_CHECKED);
  lv_obj_clear_state(btn5, LV_STATE_CHECKED);
  lv_obj_clear_state(btn6, LV_STATE_CHECKED);
  lv_obj_clear_state(btn7, LV_STATE_CHECKED);
  lv_obj_clear_state(btn8, LV_STATE_CHECKED);
  lv_obj_clear_state(btn9, LV_STATE_CHECKED);
  lv_obj_clear_state(btn10, LV_STATE_CHECKED);
    
}

void bouton2_event_cb(lv_event_t *e)
{

  color = 2; // vert
  gomme=0;
    lv_obj_clear_state(btn1, LV_STATE_CHECKED);
  lv_obj_clear_state(btn3, LV_STATE_CHECKED);
  lv_obj_clear_state(btn4, LV_STATE_CHECKED);
  lv_obj_clear_state(btn5, LV_STATE_CHECKED);
  lv_obj_clear_state(btn6, LV_STATE_CHECKED);
  lv_obj_clear_state(btn7, LV_STATE_CHECKED);
  lv_obj_clear_state(btn8, LV_STATE_CHECKED);
  lv_obj_clear_state(btn9, LV_STATE_CHECKED);
  lv_obj_clear_state(btn10, LV_STATE_CHECKED);
}
void bouton3_event_cb(lv_event_t *e)
{

  color = 3; // Jaune
  gomme=0;
    lv_obj_clear_state(btn1, LV_STATE_CHECKED);
  lv_obj_clear_state(btn2, LV_STATE_CHECKED);
  lv_obj_clear_state(btn4, LV_STATE_CHECKED);
  lv_obj_clear_state(btn5, LV_STATE_CHECKED);
  lv_obj_clear_state(btn6, LV_STATE_CHECKED);
  lv_obj_clear_state(btn7, LV_STATE_CHECKED);
  lv_obj_clear_state(btn8, LV_STATE_CHECKED);
  lv_obj_clear_state(btn9, LV_STATE_CHECKED);
  lv_obj_clear_state(btn10, LV_STATE_CHECKED);
}
void bouton4_event_cb(lv_event_t *e)
{

  color = 0; // Noir
  gomme=1;
  lv_obj_clear_state(btn1, LV_STATE_CHECKED);
  lv_obj_clear_state(btn2, LV_STATE_CHECKED);
  lv_obj_clear_state(btn3, LV_STATE_CHECKED);
  lv_obj_clear_state(btn5, LV_STATE_CHECKED);
  lv_obj_clear_state(btn6, LV_STATE_CHECKED);
  lv_obj_clear_state(btn7, LV_STATE_CHECKED);
  lv_obj_clear_state(btn8, LV_STATE_CHECKED);
  lv_obj_clear_state(btn9, LV_STATE_CHECKED);
  lv_obj_clear_state(btn10, LV_STATE_CHECKED);
}

void bouton5_event_cb(lv_event_t *e)
{

  color = 4; // Bleu
  gomme=0;
    lv_obj_clear_state(btn1, LV_STATE_CHECKED);
  lv_obj_clear_state(btn2, LV_STATE_CHECKED);
  lv_obj_clear_state(btn3, LV_STATE_CHECKED);
  lv_obj_clear_state(btn4, LV_STATE_CHECKED);
  lv_obj_clear_state(btn6, LV_STATE_CHECKED);
  lv_obj_clear_state(btn7, LV_STATE_CHECKED);
  lv_obj_clear_state(btn8, LV_STATE_CHECKED);
  lv_obj_clear_state(btn9, LV_STATE_CHECKED);
  lv_obj_clear_state(btn10, LV_STATE_CHECKED);
}
void bouton6_event_cb(lv_event_t *e)
{

  color = 5; // Bleu
  gomme=0;
   lv_obj_clear_state(btn1, LV_STATE_CHECKED);
  lv_obj_clear_state(btn2, LV_STATE_CHECKED);
  lv_obj_clear_state(btn3, LV_STATE_CHECKED);
  lv_obj_clear_state(btn4, LV_STATE_CHECKED);
  lv_obj_clear_state(btn5, LV_STATE_CHECKED);
  lv_obj_clear_state(btn7, LV_STATE_CHECKED);
  lv_obj_clear_state(btn8, LV_STATE_CHECKED);
  lv_obj_clear_state(btn9, LV_STATE_CHECKED);
  lv_obj_clear_state(btn10, LV_STATE_CHECKED);
}
void bouton7_event_cb(lv_event_t *e)
{

  color = 6; // Bleu
  gomme=0;
  lv_obj_clear_state(btn1, LV_STATE_CHECKED);
  lv_obj_clear_state(btn2, LV_STATE_CHECKED);
  lv_obj_clear_state(btn3, LV_STATE_CHECKED);
  lv_obj_clear_state(btn4, LV_STATE_CHECKED);
  lv_obj_clear_state(btn5, LV_STATE_CHECKED);
  lv_obj_clear_state(btn6, LV_STATE_CHECKED);
  lv_obj_clear_state(btn8, LV_STATE_CHECKED);
  lv_obj_clear_state(btn9, LV_STATE_CHECKED);
  lv_obj_clear_state(btn10, LV_STATE_CHECKED);
}

void bouton8_event_cb(lv_event_t *e)
{

  color = 7; // Bleu
  gomme=0;
    lv_obj_clear_state(btn1, LV_STATE_CHECKED);
  lv_obj_clear_state(btn2, LV_STATE_CHECKED);
  lv_obj_clear_state(btn3, LV_STATE_CHECKED);
  lv_obj_clear_state(btn4, LV_STATE_CHECKED);
  lv_obj_clear_state(btn5, LV_STATE_CHECKED);
  lv_obj_clear_state(btn6, LV_STATE_CHECKED);
  lv_obj_clear_state(btn7, LV_STATE_CHECKED);
  lv_obj_clear_state(btn9, LV_STATE_CHECKED);
  lv_obj_clear_state(btn10, LV_STATE_CHECKED);
}

void bouton9_event_cb(lv_event_t *e)
{
  
 
  {
    for (int i = 0; i < 64; i++)
    {
      for (int j = 0; j < 32; j++)
      {
        ecran.drawPointDirect(i, j, color);
      }
    }
  

  lv_area_set(&area, 0, 51, 480, 272);
  lv_inv_area(NULL, &area);
  gomme=0;
}
  lv_obj_clear_state(btn1, LV_STATE_CHECKED);
  lv_obj_clear_state(btn2, LV_STATE_CHECKED);
  lv_obj_clear_state(btn3, LV_STATE_CHECKED);
  lv_obj_clear_state(btn4, LV_STATE_CHECKED);
  lv_obj_clear_state(btn5, LV_STATE_CHECKED);
  lv_obj_clear_state(btn6, LV_STATE_CHECKED);
  lv_obj_clear_state(btn7, LV_STATE_CHECKED);
  lv_obj_clear_state(btn8, LV_STATE_CHECKED);
  lv_obj_clear_state(btn10, LV_STATE_CHECKED);
}
void bouton10_event_cb(lv_event_t *e)
{

  color = 0; // Bleu
  gomme=0;

    lv_obj_clear_state(btn1, LV_STATE_CHECKED);
  lv_obj_clear_state(btn2, LV_STATE_CHECKED);
  lv_obj_clear_state(btn3, LV_STATE_CHECKED);
  lv_obj_clear_state(btn4, LV_STATE_CHECKED);
  lv_obj_clear_state(btn5, LV_STATE_CHECKED);
  lv_obj_clear_state(btn6, LV_STATE_CHECKED);
  lv_obj_clear_state(btn7, LV_STATE_CHECKED);
  lv_obj_clear_state(btn8, LV_STATE_CHECKED);
  lv_obj_clear_state(btn9, LV_STATE_CHECKED);
}

void testLvgl()
{
  // Initialisations générales
  lv_obj_t *label;

  btn1 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn1, 48, 50);
  lv_obj_align(btn1, LV_ALIGN_TOP_LEFT, 0, 0);
  //lv_obj_remove_flag(btn1, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_event_cb(btn1, bouton1_event_cb, LV_EVENT_CLICKED, NULL);
  lv_obj_add_flag(btn1, LV_OBJ_FLAG_CHECKABLE);

  label = lv_label_create(btn1);
  lv_label_set_text(label, "Rouge");
  lv_obj_center(label);
  lv_obj_set_style_bg_color(btn1, lv_palette_main(LV_PALETTE_BROWN), 0);

   btn2 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn2, 48, 50);
  lv_obj_align(btn2, LV_ALIGN_TOP_LEFT, 432, 0);
  //lv_obj_remove_flag(btn2, LV_OBJ_FLAG_PRESS_LOCK);

  label = lv_label_create(btn2);
  lv_label_set_text(label, "Vert");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn2, bouton2_event_cb, LV_EVENT_CLICKED, NULL);
  lv_obj_set_style_bg_color(btn2, lv_palette_main(LV_PALETTE_GREEN), 0);
  lv_obj_add_flag(btn2, LV_OBJ_FLAG_CHECKABLE);
  

  btn3 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn3, 48, 50);
  lv_obj_align(btn3, LV_ALIGN_TOP_LEFT, 192, 0);
  //lv_obj_remove_flag(btn3, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_flag(btn3, LV_OBJ_FLAG_CHECKABLE);

  label = lv_label_create(btn3);
  lv_label_set_text(label, "Jaune");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn3, bouton3_event_cb, LV_EVENT_CLICKED, NULL);
  lv_obj_set_style_bg_color(btn3, lv_palette_main(LV_PALETTE_YELLOW), 0);

  btn4 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn4, 48, 50);
  lv_obj_align(btn4, LV_ALIGN_TOP_LEFT, 336, 0);
  //lv_obj_remove_flag(btn4, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_flag(btn4, LV_OBJ_FLAG_CHECKABLE);

  label = lv_label_create(btn4);
  lv_label_set_text(label, "Gomme");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn4, bouton4_event_cb, LV_EVENT_CLICKED, NULL);

  btn5 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn5, 48, 50);
  lv_obj_align(btn5, LV_ALIGN_TOP_LEFT, 96, 0);
  //lv_obj_remove_flag(btn5, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_flag(btn5, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_style_bg_color(btn5, lv_palette_main(LV_PALETTE_BROWN), 0);

  label = lv_label_create(btn5);
  lv_label_set_text(label, "Bleu");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn5, bouton5_event_cb, LV_EVENT_CLICKED, NULL);
  lv_obj_set_style_bg_color(btn5, lv_palette_main(LV_PALETTE_BLUE), 0);

  btn6 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn6, 48, 50);
  lv_obj_align(btn6, LV_ALIGN_TOP_LEFT, 48, 0);
 // lv_obj_remove_flag(btn6, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_flag(btn6, LV_OBJ_FLAG_CHECKABLE);

  label = lv_label_create(btn6);
  lv_label_set_text(label, "Violet");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn6, bouton6_event_cb, LV_EVENT_CLICKED, NULL);
  lv_obj_set_style_bg_color(btn6, lv_palette_main(LV_PALETTE_PURPLE), 0);

  btn7 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn7, 48, 50);
  lv_obj_align(btn7, LV_ALIGN_TOP_LEFT, 144, 0);
  //lv_obj_remove_flag(btn7, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_flag(btn7, LV_OBJ_FLAG_CHECKABLE);

  label = lv_label_create(btn7);
  lv_label_set_text(label, "Cyan");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn7, bouton7_event_cb, LV_EVENT_CLICKED, NULL);
  lv_obj_set_style_bg_color(btn7, lv_palette_main(LV_PALETTE_CYAN), 0);

  btn8 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn8, 48, 50);
  lv_obj_align(btn8, LV_ALIGN_TOP_LEFT, 240, 0);
  //lv_obj_remove_flag(btn8, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_flag(btn8, LV_OBJ_FLAG_CHECKABLE);

  label = lv_label_create(btn8);
  lv_label_set_text(label, "Blanc");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn8, bouton8_event_cb, LV_EVENT_CLICKED, NULL);
  lv_obj_set_style_bg_color(btn8, lv_palette_main(LV_PALETTE_TEAL), 0);

  btn9 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn9, 48, 50);
  lv_obj_align(btn9, LV_ALIGN_TOP_LEFT, 288, 0);
  //lv_obj_remove_flag(btn9, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_flag(btn9, LV_OBJ_FLAG_CHECKABLE);

  label = lv_label_create(btn9);
  lv_label_set_text(label, "Fullscreen");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn9, bouton9_event_cb, LV_EVENT_CLICKED, NULL);




  btn10 = lv_button_create(lv_screen_active());
  lv_obj_set_size(btn10, 48, 50);
  lv_obj_align(btn10, LV_ALIGN_TOP_LEFT, 384, 0);
  //lv_obj_remove_flag(btn10, LV_OBJ_FLAG_PRESS_LOCK);
  lv_obj_add_flag(btn10, LV_OBJ_FLAG_CHECKABLE);

  label = lv_label_create(btn10);
  lv_label_set_text(label, "Noir");
  lv_obj_center(label);
  lv_obj_add_event_cb(btn10, bouton10_event_cb, LV_EVENT_CLICKED, NULL);


   /*lv_obj_t * btn10 = lv_button_create(lv_screen_active());
  lv_obj_add_event_cb(btn10, bouton10_event_cb, LV_EVENT_ALL, NULL);
  lv_obj_align(btn10, LV_ALIGN_CENTER, 270, 0);
  lv_obj_add_flag(btn10, LV_OBJ_FLAG_CHECKABLE);
  lv_obj_set_height(btn10, LV_SIZE_CONTENT);

  label = lv_label_create(btn10);
  lv_label_set_text(label, "Noir");
  lv_obj_center(label);*/

 
}

#ifdef ARDUINO

#include "lvglDrivers.h"

// à décommenter pour tester la démo
// #include "demos/lv_demos.h"

// uint8_t draw_buf[64*7*32*7*1];

void mySetup()
{
  //  LV_DRAW_BUF_DEFINE_STATIC(draw_buf, 64*4, 32*4, LV_COLOR_FORMAT_RGB565);
  //  LV_DRAW_BUF_INIT_STATIC(draw_buf);

  // à décommenter pour tester la démo
  // lv_demo_widgets();

  // Initialisations générales
  testLvgl();

  ecran.begin(bufferEcran, 64, 32);

  // Créer un canvas
  //  canvas = lv_canvas_create(lv_screen_active());

  //  lv_canvas_set_buffer(canvas, draw_buf, 64*7, 32*7, LV_COLOR_FORMAT_I4);

  //  lv_canvas_set_draw_buf(canvas, &draw_buf);
  //  lv_canvas_fill_bg(canvas, lv_color_black(), LV_OPA_COVER);
  //  lv_obj_center(canvas);

  // lv_layer_t layer;
  // lv_canvas_init_layer(canvas, &layer);

  //   lv_draw_rect_dsc_t dsc;
  //   lv_draw_rect_dsc_init(&dsc);
  //   dsc.bg_color = lv_palette_main(LV_PALETTE_RED);
  //   dsc.border_color = lv_palette_main(LV_PALETTE_BLUE);
  //   dsc.border_width = 3;
  //   dsc.outline_color = lv_palette_main(LV_PALETTE_GREEN);
  //   dsc.outline_width = 2;
  //   dsc.outline_pad = 2;
  //   dsc.outline_opa = LV_OPA_50;
  //   dsc.radius = 5;
  //   dsc.border_width = 3;

  //   lv_area_t coords = {10, 10, 40, 30};

  //   lv_draw_rect(&layer, &dsc, &coords);

  //   lv_canvas_finish_layer(canvas, &layer);

  /*for (int i = 0; i < 32; i++)
  {
    for (int j = 0; j < 16; j++)
    {
      ecran.drawPoint(i, j, 1);
    }
  }*/
  // xTaskCreate(myMatrixTask, NULL, 16384, NULL, osPriorityNormal, NULL);
}

void loop()
{
  // lv_task_handler(); // Traiter les tâches LVGL
  // delay(5);          // Petite pause pour éviter une surcharge
  //  Inactif (pour mise en veille du processeur)
}

void myTask(void *pvParameters)
{
  int i = 0, j = 0;

  // Init
  TickType_t xLastWakeTime;
  // Lecture du nombre de ticks quand la tâche débute
  xLastWakeTime = xTaskGetTickCount();
  while (1)
  {
    lv_indev_get_point(lv_indev_get_act(), &point); // Récupérer la position du point touché
    // convertir en point ecran à led
    point.x = point.x / 7.5;
    point.y = (point.y - 51) / 6.9;
    if (point.y >= 0)
    {
      if ((point.x != oldPoint.x) || (point.y != oldPoint.y))
      {
        if (gomme == 0)
        {
          ecran.drawPointDirect(point.x, point.y, 0);
          ecran.drawPointDirect(point.x, point.y, color);
          lv_lock();
          lv_area_set(&area, point.x * 7.5, point.y * 6.9 + 51, (point.x + 1) * 7.5, (point.y + 1) * 6.9 + 51);
          lv_inv_area(NULL, &area);
          lv_unlock();
          oldPoint = point;
        }

       if (gomme == 1)
        {
          for (int i = 0; i < 4; i++)
          {
            for (int j = 0; j < 4; j++)
            {
              ecran.drawPointDirect(point.x + i, point.y + i, color);
            }
          }
          lv_lock();
          lv_area_set(&area, point.x * 7.5, point.y * 6.9 + 51, (point.x + 3) * 7.5, (point.y + 3) * 6.9 + 51);
          lv_inv_area(NULL, &area);
          lv_unlock();
        }
      }
    }
    //  Afficher les coordonnées dans le moniteur série
    //  if (point.x >= 0 && point.y >= 0)
    //{
    /* Serial.print("Touch position: x = ");
     Serial.print(point.x);
     Serial.print(", y = ");
     Serial.println(point.y);
     // }

     // Dessiner un pixel à la position touchée
     lv_canvas_set_px(canvas, point.x, point.y, LV_COLOR_RED, 255); // Dessiner un pixel rouge*/

    // Loop
    // ecran.scan();

    // Endort la tâche pendant le temps restant par rapport au réveil,
    // ici 200ms, donc la tâche s'effectue toutes les 200ms
    vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1)); // toutes les 1 ms
  }
}

void myMatrixTask(void *pvParameters)
{
  // Init
  TickType_t xLastWakeTime;
  // Lecture du nombre de ticks quand la tâche débute
  xLastWakeTime = xTaskGetTickCount();
  while (1)
  {
    // Loop
    ecran.scan();
    vTaskDelayUntil(&xLastWakeTime, pdMS_TO_TICKS(1)); // toutes les 1 ms
  }
}

#else

#include "lvgl.h"
#include "app_hal.h"
#include <cstdio>

int main(void)
{
  printf("LVGL Simulator\n");
  fflush(stdout);

  lv_init();
  hal_setup();

  testLvgl();

  hal_loop();
  return 0;
}

#endif
