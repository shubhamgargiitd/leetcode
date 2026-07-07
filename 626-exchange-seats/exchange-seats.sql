SELECT id,
  CASE 
    WHEN id % 2 = 1 AND id = (SELECT COUNT(*) FROM Seat) THEN student
    WHEN id % 2 = 1 THEN (SELECT student FROM Seat WHERE id = s.id + 1)
    WHEN id % 2 = 0 THEN (SELECT student FROM Seat WHERE id = s.id - 1)
  END AS student
FROM Seat s
ORDER BY id;