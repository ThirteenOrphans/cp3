typedef unsigned short hword;
#define BGR(r, g, b)  ((b << 10) + (g << 5) + (r))
#define VRAM ((volatile unsigned short*)0x06000000)

/* プロトタイプ宣言*/
void draw_point (hword x, hword y, hword color);

int main(void) {
    hword *ptr;
    ptr = 0x04000000;
	*ptr = 0x0F03;

    hword x1 = 100;
    hword y1 = 100;
    hword c1 = BGR(0xFF, 0x1F, 0x1F);

    draw_point(x1, y1, c1);

    printf("x1: %d, y1: %d, c1: %d\n", x1, y1, c1);
    printf("けすやつ\n");
    return 0;
}
void draw_point (hword x, hword y, hword color) {
    VRAM[y * 240 + x] = color; 
}