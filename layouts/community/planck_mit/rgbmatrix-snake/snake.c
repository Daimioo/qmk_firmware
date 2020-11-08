#include "snake.h"

snake_status_t snake_status = {
  .direction = DIRECTION_RIGHT,
  .snake = { 13, 14, 15, 16 },
  .snake_head_idx = 3,
  .snake_length = 4,
  .food = 20,
  .snake_anim_counter = 750,
  .snake_ms_per_move = 750,
};

void snake_init() {

}

// wraps around automatically
uint8_t next_cell_wraparound(uint8_t cell, char direction) {
  uint8_t row = cell / SNAKE_GRID_WIDTH;
  uint8_t col = cell % SNAKE_GRID_WIDTH;
  uint8_t next_row = row;
  uint8_t next_col = col;
  switch (direction) {
  case DIRECTION_RIGHT:
    next_col = (col == SNAKE_GRID_WIDTH - 1) ? 0 : col + 1;
    break;
  case DIRECTION_UP:
    next_row = (row == 0) ? SNAKE_GRID_HEIGHT - 1 : row - 1;
    break;
  case DIRECTION_LEFT:
    next_col = (col == 0) ? SNAKE_GRID_WIDTH - 1 : col - 1;
    break;
  case DIRECTION_DOWN:
    next_row = (row == SNAKE_GRID_HEIGHT - 1) ? 0 : row + 1;
    break;
  }
  return (next_row * SNAKE_GRID_WIDTH) + next_col;
}

void move_snake(void) {
  uint8_t snake_head_cell = snake_status.snake[snake_status.snake_head_idx];
  uint8_t next_cell = next_cell_wraparound(snake_head_cell, snake_status.direction);
  uint8_t next_snake_head_idx = (snake_status.snake_head_idx == SNAKE_LENGTH_MAX - 1) ? 0 : snake_status.snake_head_idx + 1;
  snake_status.snake[next_snake_head_idx] = next_cell;
  snake_status.snake_head_idx = next_snake_head_idx;
}

// assuming plank_mit layout has per-key RGB layout
// and only one RGB beneath the space key
void update_bitmap_from_cell(RGB bitmap[47], uint8_t cell, RGB color) {
  if (cell < 41) {
    bitmap[cell].r = color.r;
    bitmap[cell].g = color.g;
    bitmap[cell].b = color.b;
  } else if (cell == 41 || cell == 42) {
    // additive average of the two
    bitmap[41].r += color.r / 2;
    bitmap[41].g += color.g / 2;
    bitmap[41].b += color.b / 2;
  } else if (cell > 42) {
    bitmap[cell - 1].r = color.r;
    bitmap[cell - 1].g = color.g;
    bitmap[cell - 1].b = color.b;
  }
}

void render_to_bitmap(RGB bitmap[47]) {
  uint8_t snake_head_idx = snake_status.snake_head_idx;
  for (uint8_t i = 0; i < snake_status.snake_length; i++) {
    uint8_t snake_idx = (snake_head_idx >= i) ? snake_head_idx - i : SNAKE_LENGTH_MAX - (i - snake_head_idx);
    RGB snake_color = { 0xFF, 0, 0 };
    uint8_t cell = snake_status.snake[snake_idx];
    update_bitmap_from_cell(bitmap, cell, snake_color);
  }
}

void snake_update(uint32_t delta_time, RGB bitmap[47]) {
  if (snake_status.snake_anim_counter > delta_time) {
    snake_status.snake_anim_counter -= delta_time;
  } else {
    uint32_t remaining = delta_time - snake_status.snake_anim_counter;
    snake_status.snake_anim_counter = snake_status.snake_ms_per_move + remaining;
    move_snake();
  }
  render_to_bitmap(bitmap);
}
