flowchart TD
    A[Start of printf] --> B{Le format est-il nul}
    B -- Yes --> C[Retourner -1]
    B -- Non --> D[Démarrer les arguments variadiques]
    D --> E[Initialiser k = 0, count = 0]
    E --> F{le format à k n'est pas la fin}

    F -- Oui --> G{Le format à k est-il un signe de pourcentage ?}
    G -- Non --> H[Imprimer le caractère en utilisant putchar\nIncrémenter le nombre]
    H --> I[Increment k]
    I --> F

    G -- Oui --> J{Le caractère suivant est la fin}
    J -- Oui --> K[Retourner -1]
    J -- Non --> L[Increment k]
    L --> M[Appeler match_specifier\nAjouter le résultat au décompte]
    M --> N[Increment k]
    N --> F

    F -- Non --> O[Terminer les arguments variadiques]
    O --> P[Retourner count]
    P --> Q[fin de printf]
