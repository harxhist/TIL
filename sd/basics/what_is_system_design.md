## Understanding through Pizza Parlour Scaling

1. One Chef: As a manager, ask him to work hard. Optimize processes & increase throughput using same resources.(Vertical Scaling)
2. To optimize, prepare before-hand at non-peak hours.(Preprocessing & Cron Job)
3. Chef is ill: Hire a backup chef. 1 chef + 1 backup chef(Master-slave). Keep backups & avoid single point of failure.(Backups)
4. Hire more chefs(Horizontal Scaling)
5. Make specialized team of chefs good at pizza & garlic bread. These teams can scale at different rates & responsibility divides among them.(Microservice Architecture).
6. Electicity goes off in your shop. Have a backup shop at different location & serve closer order by location.
(Distributed System, partitioning, more fault tolerant)
7. System needs to decided which shop should take order to optimize delivery time.(Load Balancer)
8. Delivery Agent/customer on shop picking up order(whether pizza or burger) doesn't depend on constituents of each other. So there is separation of concerns.(Decoupling)
9. One oven goes down, churning rate goes down. Manager should be aware of this facts & why that happened.(Logging & Metrics)
10. System should be extensible

### System Design factors:
1. Vertical Scaling
2. Preprocessing
3. Backups
4. Horizontal Scaling
5. Microservices Architecture
6. Distributed System
7. Load Balancer
8. Decoupling
9. Logging & Metrics
10. Extensible


[Resource](https://www.youtube.com/watch?v=SqcXvc3ZmRU)