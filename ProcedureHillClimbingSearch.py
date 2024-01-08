import random

def objective_function(solution):
    # Xác định hàm mục tiêu của bạn ở đây 
    # Hàm này sẽ đánh giá chất lượng của giải pháp và trả về một giá trị 
    # Giá trị càng cao thì giải pháp càng tốt 
    # Sửa đổi chức năng này dựa trên vấn đề tối ưu hóa cụ thể của bạn
    return sum(solution)

def generate_neighbor(current_solution):
    # Tạo giải pháp lân cận bằng cách thực hiện một sửa đổi nhỏ cho giải pháp hiện tại 
    # Hàm này sẽ triển khai logic để tạo ra giải pháp lân cận 
    # Sửa đổi chức năng này dựa trên vấn đề tối ưu hóa cụ thể của bạn
    neighbor = current_solution[:]
    index = random.randint(0, len(neighbor) - 1)
    neighbor[index] = 1 - neighbor[index]  # Flip the value at the selected index
    return neighbor

def hill_climbing():
    # Khởi tạo
    current_solution = [random.randint(0, 1) for _ in range(10)]  # Tạo ra nút ban đầu
    current_fitness = objective_function(current_solution)

    # Lặp quá trình
    while True:
        # Nút kề
        neighbor = generate_neighbor(current_solution)
        neighbor_fitness = objective_function(neighbor)

        # So sánh
        if neighbor_fitness >= current_fitness:
            current_solution = neighbor
            current_fitness = neighbor_fitness
        else:
            break  # Thoát vòng lặp nếu ko có giá trị nào tốt hơn

    return current_solution, current_fitness


best_solution, best_fitness = hill_climbing()
print("Best Solution:", best_solution)
print("Best Fitness:", best_fitness)