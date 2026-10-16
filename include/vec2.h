#pragma once
#include <math.h>

typedef struct Vec2 {
  float x;
  float y;
} vec2_t;

static inline vec2_t vec2_add(vec2_t a, vec2_t b) {
  return (vec2_t){a.x + b.x, a.y + b.y};
}

static inline vec2_t vec2_sub(vec2_t a, vec2_t b) {
  return (vec2_t){a.x - b.x, a.y - b.y};
}

static inline vec2_t vec2_scale(vec2_t v, float s) {
  return (vec2_t){v.x * s, v.y * s};
}

static inline float vec2_len_sq(vec2_t v) { return v.x * v.x + v.y * v.y; }

static inline float vec2_len(vec2_t v) { return sqrtf(vec2_len_sq(v)); }

static inline vec2_t vec2_limit(vec2_t v, float max) {
  float len_sq = vec2_len_sq(v);
  if (len_sq > max * max) {
    return vec2_scale(v, max / sqrtf(len_sq));
  }
  return v;
}