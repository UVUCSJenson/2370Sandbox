// shape2.rs: Shows how to do implement a custom trait
use std::f64::consts::PI;

trait HasArea {
    fn area(&self) -> f64;
}

struct Circle {
    radius: f64,
}

impl HasArea for Circle {
    fn area(&self) -> f64 {
        PI * (self.radius * self.radius)
    }
}

struct Rectangle {
    len: f64,
    wid: f64,
}

impl HasArea for Rectangle {
    fn area(&self) -> f64 {
        self.len * self.wid
    }
}

fn print_area(item: &impl HasArea) {
    println!("{}", item.area());
}

fn main() {
    let c = Circle{radius: 3.0};
    print_area(&c);
}
